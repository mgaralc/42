import sys


def parse_inventory(args):
    inv = {}

    for arg in args:
        try:
            name, quantity = arg.split(":")
            inv[name] = int(quantity)
        except ValueError:
            print("Error: invalid input format")
            sys.exit(1)

    return inv


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("Error: You must enter data")
        sys.exit(1)

    inv = parse_inventory(sys.argv[1:])

    print("=== Inventory System Analysis ===")
    print(inv)

    total_items = sum(inv.values())
    print(f"Total items in inventory: {total_items}")
    print(f"Unique item types: {len(inv)}")

    print("\n=== Current Inventory ===")
    for name, quantity in inv.items():
        percent = 0.0
        if total_items != 0:
            percent = (quantity / total_items) * 100
        print(f"{name}: {quantity} units ({percent:.1f}%)")

    print("\n=== Inventory Statistics ===")

    most_name = None
    most_qty = None

    for name, quantity in inv.items():
        if most_qty is None or quantity > most_qty:
            most_name = name
            most_qty = quantity

    print(f"Most abundant: {most_name} ({most_qty} units)")

    least_name = None
    least_qty = None

    for name, quantity in inv.items():
        if least_qty is None or quantity < least_qty:
            least_name = name
            least_qty = quantity

    unit_word = "unit" if least_qty == 1 else "units"
    print(f"Least abundant: {least_name} ({least_qty} {unit_word})")

    print("\n=== Item Categories ===")
    moderate = {}
    scarce = {}

    for name, quantity in inv.items():
        if quantity >= 4:
            moderate[name] = quantity
        else:
            scarce[name] = quantity

    print(f"Moderate: {moderate}")
    print(f"Scarce: {scarce}")

    print("\n=== Management Suggestions ===")

    restock = []
    for name, quantity in inv.items():
        if quantity == 1:
            restock.append(name)

    print(f"Restock needed: {restock}")

    print("\n=== Dictionary Properties Demo ===")
    print(f"Dictionary keys: {list(inv.keys())}")
    print(f"Dictionary values: {list(inv.values())}")
    print(f"Sample lookup - 'sword' in inventory: {'sword' in inv}")
