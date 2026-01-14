class Plant:
    """Base plant model with common attributes shared by all plant types."""

    def __init__(self, nombre: str, altura: int, edad: int) -> None:
        """Initialize a plant with name, height (cm), and age (days)."""
        self.nombre = nombre
        self.altura = altura
        self.edad = edad


class Flower(Plant):
    """Flower plant type with a color and blooming behavior."""

    def __init__(
        self,
        nombre: str,
        altura: int,
        edad: int,
        color: str,
    ) -> None:
        """Initialize a flower with base attributes plus a color."""
        super().__init__(nombre, altura, edad)
        self.color = color

    def bloom(self) -> None:
        """Print the flower blooming message."""
        print(f"{self.nombre} is blooming beautifully!")


class Tree(Plant):
    """Tree plant type with a trunk diameter and shade production behavior."""

    def __init__(
        self,
        nombre: str,
        altura: int,
        edad: int,
        trunk_diameter: int,
    ) -> None:
        """Initialize a tree with base attributes plus trunk diameter (cm)."""
        super().__init__(nombre, altura, edad)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        """Print the tree shade production message."""
        print(
            f"{self.nombre} provides {self.trunk_diameter} "
            "square meters of shade"
        )


class Vegetable(Plant):
    """Vegetable plant type with harvest season and nutritional value."""

    def __init__(
        self,
        nombre: str,
        altura: int,
        edad: int,
        harvest_season: str,
        nutritional_value: str,
    ) -> None:
        """Initialize a vegetable with base plus harvest/nutrition."""
        super().__init__(nombre, altura, edad)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show_nutrition(self) -> None:
        """Print the vegetable nutrition message."""
        print(f"{self.nombre} is rich in {self.nutritional_value}")


if __name__ == "__main__":
    flower_data = [
        ("Rose", 25, 30, "pink"),
        ("Tulipan", 40, 20, "white"),
    ]
    tree_data = [
        ("Roble", 150, 239, 50),
        ("Oak", 240, 130, 80),
    ]
    vegetable_data = [
        ("Tomato", 30, 15, "summer", "vitamin C"),
        ("Carrot", 20, 40, "autumn", "beta-carotene"),
    ]

    flowers = []
    for name, height, age, color in flower_data:
        flowers.append(Flower(name, height, age, color))

    trees = []
    for name, height, age, trunk_diameter in tree_data:
        trees.append(Tree(name, height, age, trunk_diameter))

    vegetables = []
    for name, height, age, harvest_season, nutritional_value in vegetable_data:
        vegetables.append(
            Vegetable(name, height, age, harvest_season, nutritional_value)
        )

    print("=== Garden Plant Types ===")

    for flower in flowers:
        print(
            f"{flower.nombre} (Flower): {flower.altura}cm, "
            f"{flower.edad} days, {flower.color} color"
        )
        flower.bloom()

    for tree in trees:
        print(
            f"{tree.nombre} (Tree): {tree.altura}cm, "
            f"{tree.edad} days, trunk {tree.trunk_diameter}cm"
        )
        tree.produce_shade()

    for vegetable in vegetables:
        print(
            f"{vegetable.nombre} (Vegetable): {vegetable.altura}cm, "
            f"{vegetable.edad} days, harvest {vegetable.harvest_season}"
        )
        vegetable.show_nutrition()
