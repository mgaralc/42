from datetime import datetime
from typing import Optional

from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(None, max_length=200)


if __name__ == "__main__":
    print("Space Station Data Validation")
    print("========================================")

    try:
        work = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance="2024-01-01T10:30:00",
        )

        print("Valid station created:")
        print(f"ID: {work.station_id}")
        print(f"Name: {work.name}")
        print(f"Crew: {work.crew_size} people")
        print(f"Power: {work.power_level}%")
        print(f"Oxygen: {work.oxygen_level}%")
        status = "Operational" if work.is_operational else "Not Operational"
        print(f"Status: {status}")

    except ValidationError as e:
        print("Validation Error")
        print(e)

    print("========================================")

    try:
        SpaceStation(
            station_id="ISS002",
            name="Test Station",
            crew_size=21,
            power_level=50.0,
            oxygen_level=50.0,
            last_maintenance="2024-01-01T10:30:00",
        )
    except ValidationError as e:
        print("Expected validation error:")
        print(e.errors()[0]["msg"])