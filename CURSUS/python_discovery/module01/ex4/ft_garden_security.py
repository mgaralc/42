class SecurePlant:
    """A plant model that validates and encapsulates height and age."""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Initialize a secure plant with name, height (cm), and age (days)."""
        self.name = name
        self._height = height
        self._age = age

    def get_height(self) -> int:
        """Return the current height in centimeters."""
        return self._height

    def set_height(self, new_height: int) -> None:
        """Set height if non-negative; otherwise reject the operation."""
        if new_height >= 0:
            self._height = new_height
            print(f"Height updated: {self._height}cm [OK]")
        else:
            print(
                f"Invalid operation attempted: height {new_height}cm "
                "[REJECTED]"
            )
            print("Security: Negative height rejected")

    def get_age(self) -> int:
        """Return the current age in days."""
        return self._age

    def set_age(self, new_age: int) -> None:
        """Set age if non-negative; otherwise reject the operation."""
        if new_age >= 0:
            self._age = new_age
            print(f"Age updated: {self._age} days [OK]")
        else:
            print(
                f"Invalid operation attempted: age {new_age} days "
                "[REJECTED]"
            )
            print("Security: Negative age rejected")


if __name__ == "__main__":
    print("=== Garden Security System ===")

    plant = SecurePlant("Rose", 25, 30)
    print(f"Plant created: {plant.name}")

    plant.set_height(25)
    plant.set_age(30)

    plant.set_height(-5)

    print(
        f"Current plant: {plant.name} "
        f"({plant.get_height()}cm, {plant.get_age()} days)"
    )
