class Plant:
    """Represents a plant that can grow and age."""
    def __init__(self, nombre, altura, edad):
        self.nombre = nombre
        self.altura = altura
        self.edad = edad

    def grow(self):
        """Increase plant height by 2 every day of grow"""
        self.altura = self.altura + 2

    def age(self):
        """Increase plant age by 1 every day of grow"""
        self.edad = self.edad + 1

    def get_info(self):
        """Print current plant information."""
        print(f"{self.nombre}: {self.altura}cm, {self.edad} days old")


if __name__ == "__main__":
    planta1 = Plant("Rose", 25, 30)
    planta2 = Plant("Sunflower", 80, 45)
    planta3 = Plant("Cactus", 15, 120)

    print("=== Garden Plant Registry ===")
    for i in range(1, 8):
        print(f"=== Day {i} ===")
        planta1.get_info()
        planta2.get_info()
        planta3.get_info()
        planta1.grow()
        planta2.grow()
        planta3.grow()
        planta1.age()
        planta2.age()
        planta3.age()
