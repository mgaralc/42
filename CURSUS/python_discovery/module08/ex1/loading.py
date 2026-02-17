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

    if missing:
        print(f"You must install {missing}")
        print("You have to use:")
        print("pip install -r requirements.txt")
        sys.exit()
    else:
        for name, module in installed.items():

            print(f"Module {name} {module.__version__}")
