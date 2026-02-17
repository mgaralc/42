import sys


def join_keys(inv):
    out = ""
    for k in inv.keys():
        if out:
            out += ", "
        out += k
    return out


def join_values(inv):
    out = ""
    for item in inv.values():
        if out:
            out += ", "
        out += str(item.get("quantity", 0))
    return out


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("No inventory provided. Usage: python3 ft_inventory_system.py "
              "item:qty item:qty ...")
        sys.exit(1)

    inventory = {}

    for arg in sys.argv[1:]:
        try:
            name, qty_str = arg.split(":")
            qty = int(qty_str)
        except ValueError:
            print("Error: invalid input format")
            sys.exit(1)

        item = inventory.get(name)
        if item is None:
            inventory[name] = {
                "name": name,
                "type": "item",
                "quantity": qty,
                "value": 0,
            }
        else:
            item.update({"quantity": item["quantity"] + qty})

    print("=== Inventory System Analysis ===")

    total_items = 0
    for item in inventory.values():
        total_items += item.get("quantity", 0)

    print(f"Total items in inventory: {total_items}")
    print(f"Unique item types: {len(inventory)}")

    print("=== Current Inventory ===")
    for name, item in inventory.items():
        quantity = item.get("quantity", 0)
        percent = 0.0
        if total_items != 0:
            percent = (quantity / total_items) * 100
        print(f"{name}: {quantity} units ({percent:.1f}%)")

    print("=== Inventory Statistics ===")
    most_name = None
    most_qty = None
    least_name = None
    least_qty = None

    for name, item in inventory.items():
        qty = item.get("quantity", 0)
        if most_qty is None or qty > most_qty:
            most_name = name
            most_qty = qty
        if least_qty is None or qty < least_qty:
            least_name = name
            least_qty = qty

    print(f"Most abundant: {most_name} ({most_qty} units)")
    print(f"Least abundant: {least_name} ({least_qty} units)")

    print("=== Item Categories ===")

    moderate = {}
    scarce = {}

    for name, item in inventory.items():
        qty = item.get("quantity", 0)

        if qty >= 4:
            moderate.update({name: qty})
        else:
            scarce.update({name: qty})

    print(f"Moderate: {moderate}")
    print(f"Scarce: {scarce}")

    print("=== Management Suggestions ===")
    restock = []
    for name, item in inventory.items():
        if item.get("quantity", 0) == 1:
            restock.append(name)
    print(f"Restock needed: {restock}")

    print("=== Dictionary Properties Demo ===")
    print(f"Dictionary keys: {join_keys(inventory)}")
    print(f"Dictionary values: {join_values(inventory)}")
    print(f"Sample lookup - 'sword' in inventory: {'sword' in inventory}")
