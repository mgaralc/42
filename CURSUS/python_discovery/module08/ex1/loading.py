import importlib
import sys


if __name__ == "__main__":
    dependencies = ["pandas", "numpy", "matplotlib"]
    missing = []
    installed = {}

    for name in dependencies:
        try:
            installed[name] = importlib.import_module(name)
        except ImportError:
            missing.append(name)

    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    if missing:
        print("Missing dependencies detected:")
        for dep in missing:
            print(f" - {dep}")
        print("Install using:")
        print("pip install -r requirements.txt")
        print("or")
        print("poetry install")
        sys.exit(1)

    for name, module in installed.items():
        if name == "pandas":
            print(
                f"[OK] {name} {module.__version__} "
                "- Data manipulation ready"
            )
        elif name == "numpy":
            print(
                f"[OK] {name} {module.__version__} "
                "- Numerical processing ready"
            )
        elif name == "matplotlib":
            print(
                f"[OK] {name} {module.__version__} "
                "- Visualization ready"
            )

    np = installed["numpy"]
    pd = installed["pandas"]
    plt = importlib.import_module("matplotlib.pyplot")

    spins = np.random.randint(0, 37, 1000)
    df = pd.DataFrame(spins, columns=["number"])

    red_numbers = [
        1, 3, 5, 7, 9, 12, 14, 16, 18,
        19, 21, 23, 25, 27, 30, 32, 34, 36
    ]

    colors = []
    for number in df["number"]:
        if number == 0:
            colors.append("green")
        elif number in red_numbers:
            colors.append("red")
        else:
            colors.append("black")

    df["color"] = colors
    counts = df["color"].value_counts()

    print("\nANALYSIS RESULTS")
    print(f"Total spins: {len(df)}")
    for color, count in counts.items():
        print(f"{color.capitalize()}: {count}")

    plt.bar(counts.index, counts.values)
    plt.savefig("matrix_analysis.png")
    plt.close()

    print("\nResults saved to matrix_analysis.png")
