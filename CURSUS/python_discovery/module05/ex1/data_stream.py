from abc import ABC, abstractmethod
from typing import Any, Dict, List, Optional, Union


Stats = Dict[str, Union[str, int, float]]


class DataStream(ABC):
    def __init__(self, stream_id: str, stream_type: str) -> None:
        self.stream_id: str = stream_id
        self.stream_type: str = stream_type
        self._stats: Stats = {}

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        raise NotImplementedError

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> List[Any]:
        return data_batch

    def get_stats(self) -> Stats:
        return dict(self._stats)


class StreamProcessor:
    def __init__(self, streams: Optional[List[DataStream]] = None) -> None:
        self.streams: List[DataStream] = streams if streams is not None else []

    def add_stream(self, stream: DataStream) -> None:
        self.streams.append(stream)

    def process_all(
        self,
        batches: List[List[Any]],
        criteria: Optional[str] = None,
    ) -> List[str]:
        results: List[str] = []
        for stream, batch in zip(self.streams, batches):
            try:
                filtered = stream.filter_data(batch, criteria)
                results.append(stream.process_batch(filtered))
            except Exception as exc:
                results.append(
                    f"[{stream.stream_id}] error: {exc}"
                )
        return results


class SensorStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id, "Environmental Data")

    @staticmethod
    def _parse_kv(item: Any) -> Optional[tuple[str, float]]:
        if not isinstance(item, str) or ":" not in item:
            return None
        key, raw = item.split(":", 1)
        key = key.strip().lower()
        raw = raw.strip()
        try:
            val = float(raw)
        except ValueError:
            return None
        return key, val

    def process_batch(self, data_batch: List[Any]) -> str:
        readings: List[tuple[str, float]] = []
        for item in data_batch:
            parsed = self._parse_kv(item)
            if parsed is not None:
                readings.append(parsed)

        count: int = len(readings)

        temps: List[float] = []
        for key, value in readings:
            if key == "temp":
                temps.append(value)

        self._stats = {
            "stream_id": self.stream_id,
            "stream_type": self.stream_type,
            "readings": count,
            "avg_temp": 0.0,
        }

        if temps:
            avg_temp: float = sum(temps) / len(temps)
            self._stats["avg_temp"] = avg_temp
            return (
                f"Sensor analysis: {count} readings processed, "
                f"avg temp: {avg_temp:.1f}°C"
            )
        return f"Sensor analysis: {count} readings processed"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> List[Any]:
        if criteria != "high":
            return data_batch
        filtered: List[Any] = []
        for item in data_batch:
            parsed = self._parse_kv(item)
            if parsed is None:
                continue
            key, val = parsed
            if key == "temp" and val > 30.0:
                filtered.append(item)
        return filtered


class TransactionStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id, "Financial Data")

    @staticmethod
    def _parse_tx(item: Any) -> Optional[tuple[str, float]]:
        if not isinstance(item, str) or ":" not in item:
            return None
        kind, raw = item.split(":", 1)
        kind = kind.strip().lower()
        raw = raw.strip()
        if kind not in ("buy", "sell"):
            return None
        try:
            amount = float(raw)
        except ValueError:
            return None
        return kind, amount

    def process_batch(self, data_batch: List[Any]) -> str:
        ops: List[tuple[str, float]] = []
        for item in data_batch:
            parsed = self._parse_tx(item)
            if parsed is not None:
                ops.append(parsed)

        net: float = 0.0
        for kind, amount in ops:
            if kind == "buy":
                net += amount
            else:
                net -= amount

        self._stats = {
            "stream_id": self.stream_id,
            "stream_type": self.stream_type,
            "operations": len(ops),
            "net_flow": net,
        }

        sign = "+" if net >= 0 else "-"
        return (
            f"Transaction analysis: {len(ops)} operations, "
            f"net flow: {sign}{abs(net):.0f} units"
        )

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> List[Any]:
        if criteria != "high":
            return data_batch
        filtered: List[Any] = []
        for item in data_batch:
            parsed = self._parse_tx(item)
            if parsed is None:
                continue
            _, amount = parsed
            if amount >= 100.0:
                filtered.append(item)
        return filtered


class EventStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id, "System Events")

    def process_batch(self, data_batch: List[Any]) -> str:
        events: List[str] = [e for e in data_batch if isinstance(e, str)]
        errors: List[str] = [e for e in events if e.strip().lower() == "error"]

        self._stats = {
            "stream_id": self.stream_id,
            "stream_type": self.stream_type,
            "events": len(events),
            "errors": len(errors),
        }

        if len(errors) == 1:
            return f"Event analysis: {len(events)} events, 1 error detected"
        return f"Event analysis: {len(events)} events, {len(errors)} errors"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> List[Any]:
        if criteria != "high":
            return data_batch
        return [
            e for e in data_batch
            if isinstance(e, str) and e.strip().lower() == "error"
        ]


def fmt_list(items: List[Any]) -> str:
    """Formato simple tipo ejemplo: [a, b, c]"""
    return "[" + ", ".join(str(x) for x in items) + "]"


if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")

    sensor = SensorStream("SENSOR_001")
    trans = TransactionStream("TRANS_001")
    events = EventStream("EVENT_001")

    processor = StreamProcessor([sensor, trans, events])

    batches = [
        ["temp:22.5", "humidity:65", "pressure:1013"],
        ["buy:100", "sell:150", "buy:75"],
        ["login", "error", "logout"],
    ]

    print("\n=== Processing (no filter) ===")
    for stream, out in zip(processor.streams, processor.process_all(batches)):
        print(out)
        print("Stats:", stream.get_stats())

    print("\n=== Processing (filter='high') ===")
    for stream, out in zip(
        processor.streams,
        processor.process_all(batches, criteria="high"),
    ):
        print(out)
        print("Stats:", stream.get_stats())
