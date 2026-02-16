from abc import ABC, abstractmethod
from typing import Any, Protocol


class ProcessingStage(Protocol):
    def process(self, data: Any) -> Any:
        pass


class ProcessingPipeline(ABC):
    def __init__(self) -> None:
        self.stages: list[ProcessingStage] = []

    def add_stage(self, stage: ProcessingStage) -> None:
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass


class NexusManager:
    def __init__(self) -> None:
        self.pipelines: list[ProcessingPipeline] = []
        self.error = 0
        self.pipeline_cont = 0

    def add_pipeline(self, pipeline: ProcessingPipeline) -> None:
        self.pipelines.append(pipeline)

    def process(self, data: Any) -> Any:
        self.error = 0
        self.pipeline_cont = 0
        current = data
        for pipeline in self.pipelines:
            try:
                current = pipeline.process(current)
                self.pipeline_cont += 1
            except Exception:
                self.error += 1
        return current


class InputStage:
    def process(self, data: Any) -> dict[str, Any]:
        if isinstance(data, dict):
            return {"data_format": "json", "payload": data}
        elif isinstance(data, str):
            return {"data_format": "csv", "raw": data}
        elif isinstance(data, list) or isinstance(data, tuple):
            return {"data_format": "stream", "items": list(data)}
        raise ValueError("Unsupported data format")


class TransformStage:
    def process(self, data: Any) -> dict[str, Any]:
        if not isinstance(data, dict):
            return {"data_format": "unknown",
                    "validated": False, "status": "invalid",
                    "message": "Invalid pipeline data"}

        if data["data_format"] == "json":
            value = data["payload"].get("value")

            if not isinstance(value, (int, float)):
                data["validated"] = False
                data["status"] = "invalid"
                data["message"] = "Invalid temperature data"
                return data

            if value > 30:
                data["validated"] = True
                data["status"] = "hot"
                data["message"] = "High temperature detected"
            elif value < 0:
                data["validated"] = True
                data["status"] = "cold"
                data["message"] = "Low temperature detected"
            else:
                data["validated"] = True
                data["status"] = "normal"
                data["message"] = "Temperature within normal range"
            return data

        elif data["data_format"] == "csv":
            raw = data.get("raw", "").strip()

            if not raw:
                data["validated"] = False
                data["status"] = "invalid"
                data["message"] = "No data received"
                data["actions_processed"] = 0
                return data

            lines = raw.splitlines()
            data["actions_processed"] = max(1, len(lines) - 1)
            data["validated"] = True
            data["status"] = "ok"
            data["message"] = f"{data['actions_processed']} actions processed"
            return data

        elif data["data_format"] == "stream":
            items = data.get("items")

            if not items:
                data["n_events"] = 0
                data["validated"] = False
                data["status"] = "invalid"
                data["message"] = "No data"
                return data

            total = 0
            valid_items: list[float] = []
            for item in items:
                if isinstance(item, (int, float)):
                    total += item
                    valid_items.append(float(item))

            if len(valid_items) == 0:
                data["n_events"] = 0
                data["validated"] = False
                data["status"] = "invalid"
                data["message"] = "No valid stream data"
                return data

            avg = total / len(valid_items)
            data["n_events"] = len(valid_items)
            data["average"] = avg
            data["validated"] = True
            data["status"] = "ok"
            data["message"] = f"{data['n_events']} readings, avg: {avg}"
            return data

        return data


class OutputStage:
    def process(self, data: Any) -> str:
        if data.get("data_format") == "json":
            value = data["payload"].get("value")
            msg = data.get("message")
            return f"Output: Processed temperature reading: {value} ({msg})"

        elif data.get("data_format") == "csv":
            actions = data.get("actions_processed", 0)
            return f"Output: User activity logged: {actions} actions processed"

        elif data.get("data_format") == "stream":
            average = data.get("average", 0)
            n_events = data.get("n_events", 0)
            return (
                f"Output: Stream summary: {n_events} readings, "
                f"avg: {average}"
            )
        return str(data)


class JSONAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        super().__init__()
        self.pipeline_id = pipeline_id
        self.add_stage(InputStage())
        self.add_stage(TransformStage())
        self.add_stage(OutputStage())

    def process(self, data: Any) -> str:
        try:
            if not isinstance(data, dict):
                raise TypeError("JSONAdapter expects a dict")

            current: Any = data
            for stage in self.stages:
                current = stage.process(current)

            return str(current)
        except Exception as exc:
            return f"[{self.pipeline_id}] error: {exc}"


class CSVAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        super().__init__()
        self.pipeline_id = pipeline_id
        self.add_stage(InputStage())
        self.add_stage(TransformStage())
        self.add_stage(OutputStage())

    def process(self, data: Any) -> str:
        try:
            if not isinstance(data, str):
                raise TypeError("CSVAdapter expects a str")

            current: Any = data
            for stage in self.stages:
                current = stage.process(current)

            return str(current)
        except Exception as exc:
            return f"[{self.pipeline_id}] error: {exc}"


class StreamAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        super().__init__()
        self.pipeline_id = pipeline_id
        self.add_stage(InputStage())
        self.add_stage(TransformStage())
        self.add_stage(OutputStage())

    def process(self, data: Any) -> str:
        try:
            if not isinstance(data, (list, tuple)):
                raise TypeError("StreamAdapter expects a list or tuple")

            current: Any = data
            for stage in self.stages:
                current = stage.process(current)

            return str(current)
        except Exception as exc:
            return f"[{self.pipeline_id}] error: {exc}"


if __name__ == "__main__":
    print("=== CODE NEXUS - PIPELINE SYSTEM ===\n")

    manager = NexusManager()
    json_pipeline = JSONAdapter("json_pipeline")
    csv_pipeline = CSVAdapter("csv_pipeline")
    stream_pipeline = StreamAdapter("stream_pipeline")

    print("=== Multi-Format Data Processing ===\n")

    print("Processing JSON data through pipeline...")
    json_data = {"sensor": "temp", "value": 23.5, "unit": "C"}
    print(f"Input: {json_data}")
    print("Stages: Input -> Transform -> Output")
    print(json_pipeline.process(json_data), end="\n\n")

    print("Processing CSV data through pipeline...")
    csv_data = "user,action,timestamp"
    print(f'Input: "{csv_data}"')
    print("Stages: Input -> Transform -> Output")
    print(csv_pipeline.process(csv_data), end="\n\n")

    print("Processing Stream data through pipeline...")
    stream_data = [20.5, 22.0, 21.5, 22.1, 24.0]
    print(f"Input: {stream_data}")
    print("Stages: Input -> Transform -> Output")
    print(stream_pipeline.process(stream_data), end="\n\n")

    print("=== Pipeline Chaining Demo ===\n")
    manager.add_pipeline(json_pipeline)
    chained_result = manager.process(json_data)
    print(f"Chain result: {chained_result}")
    print(
        f"Stats: pipelines_run={manager.pipeline_cont}, errors={manager.error}"
    )
