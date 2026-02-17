import sys
import os
import site

if __name__ == "__main__":
    prefix = sys.prefix
    base_prefix = sys.base_prefix
    executable = sys.executable

    rutas = []
    try:
        rutas = site.getsitepackages()
    except Exception:
        print("Error al guardar las rutas")

    if prefix == base_prefix:
        print("Outside the Matrix")
        print("MATRIX STATUS: You're still plugged in")
        print(f"Current Python: {executable}")
        print("Virtual Environment: None detected")
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.")
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate  # On Unix")
        print("matrix_env\\Scripts\\activate   # On Windows")
        if rutas:
            print(f"Package installation path: {rutas[0]}")
        else:
            print("No packages installed")
    else:
        print("Inside the Construct")
        print("MATRIX STATUS: Welcome to the construct")
        print(f"Current Python: {executable}")
        print(f"Virtual Environment: {os.path.basename(prefix)}")
        print(f"Environment Path: {prefix}")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting")
        print("the global system.")
        if rutas:
            print(f"Package installation path: {rutas[0]}")
        else:
            print("No packages installed")
