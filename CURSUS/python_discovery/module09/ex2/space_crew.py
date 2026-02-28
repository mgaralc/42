from datetime import datetime
from enum import Enum
from typing import List

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: List[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate_business_rules(self) -> "SpaceMission":

        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        has_leader = False
        for member in self.crew:
            if member.rank == Rank.commander:
                has_leader = True
            if member.rank == Rank.captain:
                has_leader = True

        if not has_leader:
            raise ValueError(
                "Must have at least one Commander or Captain"
            )

        for member in self.crew:
            if member.is_active is False:
                raise ValueError("All crew members must be active")

        if self.duration_days > 365:
            experienced_count = 0

            for member in self.crew:
                if member.years_experience >= 5:
                    experienced_count += 1

            total_crew = len(self.crew)

            if experienced_count * 2 < total_crew:
                raise ValueError(
                    "Long missions (> 365 days) need 50% experienced (5+years)"
                )

        return self


if __name__ == "__main__":
    print("Space Mission Crew Validation")
    print("=========================================")

    try:
        mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date="2024-01-01T10:30:00",
            duration_days=900,
            budget_millions=2500.0,
            crew=[
                CrewMember(
                    member_id="CM001",
                    name="Sarah Connor",
                    rank=Rank.commander,
                    age=45,
                    specialization="Mission Command",
                    years_experience=12,
                ),
                CrewMember(
                    member_id="CM002",
                    name="John Smith",
                    rank=Rank.lieutenant,
                    age=34,
                    specialization="Navigation",
                    years_experience=6,
                ),
                CrewMember(
                    member_id="CM003",
                    name="Alice Johnson",
                    rank=Rank.officer,
                    age=29,
                    specialization="Engineering",
                    years_experience=5,
                ),
            ],
        )

        print("Valid mission created:")
        print(f"Mission: {mission.mission_name}")
        print(f"ID: {mission.mission_id}")
        print(f"Destination: {mission.destination}")
        print(f"Duration: {mission.duration_days} days")
        print(f"Budget: ${mission.budget_millions}M")
        print(f"Crew size: {len(mission.crew)}")
        print("Crew members:")
        for member in mission.crew:
            print(
                f"- {member.name} ({member.rank.value})"
                f" - {member.specialization}"
            )

    except ValidationError as exc:
        print(exc)

    print("=========================================")

    try:
        SpaceMission(
            mission_id="M2024_BAD",
            mission_name="Test Mission",
            destination="Moon",
            launch_date="2024-01-01T10:30:00",
            duration_days=30,
            budget_millions=100.0,
            crew=[
                CrewMember(
                    member_id="CM010",
                    name="Bob Brown",
                    rank=Rank.officer,
                    age=30,
                    specialization="Science",
                    years_experience=2,
                )
            ],
        )
    except ValidationError as exc:
        print("Expected validation error:")
        print(exc.errors()[0]["msg"])
