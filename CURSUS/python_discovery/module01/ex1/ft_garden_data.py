class Plant:
    """Create class plant with atributes"""
    def __init__(self, nombre, altura, edad):
        self.nombre = nombre
        self.altura = altura
        self.edad = edad


if __name__ == "__main__":
    """"Define the content and show it"""
    planta1 = Plant("Rose", 25, 30)
    planta2 = Plant("Sunflower", 80, 45)
    planta3 = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    print(f"{planta1.nombre}: {planta1.altura}cm, {planta1.edad} days old")
    print(f"{planta2.nombre}: {planta2.altura}cm, {planta2.edad} days old")
    print(f"{planta3.nombre}: {planta3.altura}cm, {planta3.edad} days old")
