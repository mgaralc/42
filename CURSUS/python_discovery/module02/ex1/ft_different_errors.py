def garden_operations():
    int("abc")
    8 / 0
    open("missing.txt")
    plant = {"tomato": 5}
    plant["tulipan"]


def test_error_types():
    print("=== Garden Error Types Demo ===")

    print("Testing ValueError...")
    try:
        int("abc")
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    print("Testing ZeroDivisionError...")
    try:
        8 / 0
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")

    print("Testing FileNotFoundError...")
    try:
        ejem = open('archivo.txt', 'r')
        ejem.close()

    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'archivo.txt\n'")

    print("Testing KeyError...")
    try:
        diccionario = {"nombre": "Juan", "edad": 27, "peso": 75}
        diccionario["estatura"]
    except KeyError:
        print("Caught KeyError: 'missing\\_plant'\n")

    print("Testing multiple errors together...")
    try:
        int("abc")
    except (ValueError, ZeroDivisionError):
        print("Caught an error, but program continues!\n")

    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
