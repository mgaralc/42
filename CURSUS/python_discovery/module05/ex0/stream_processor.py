from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if not isinstance(data, list) or len(data) == 0:
            return False
        for i in data:
            if not isinstance(i, (int, float)):
                return False
        return True

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid numeric data")

        total = 0
        cont = 0

        for i in data:
            total += i
            cont += 1

        avg = total / cont
        return f"Processed {cont} numeric values, sum={total}, avg={avg:.2f}"


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        return isinstance(data, str)

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid text data")

        chars = len(data)
        words = len(data.split())
        return f"Processed text: {chars} characters, {words} words"


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        return isinstance(data, str) and ":" in data

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("Invalid log data")

        level, message = data.split(":", 1)
        level = level.strip().upper()
        message = message.strip()

        if level == "ERROR":
            return f"[ALERT] {level} level detected: {message}"
        return f"[INFO] {level} level detected: {message}"


if __name__ == "__main__":
    processors = [
        NumericProcessor(),
        TextProcessor(),
        LogProcessor(),
    ]

    data_samples = [
        [1, 2, 3, 4.5],
        "Hello world from 42",
        "error: disk not found",
    ]

    for processor, data in zip(processors, data_samples):
        try:
            result = processor.process(data)
            print(processor.format_output(result))
        except ValueError as exc:
            print(f"Error: {exc}")
