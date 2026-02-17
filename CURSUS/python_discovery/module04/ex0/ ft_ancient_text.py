def main() -> None:
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print("Accessing Storage Vault: ancient_fragment.txt")

    try:
        file = open("ancient_fragment.txt", "r")
    except FileNotFoundError:
        print("ERROR: Storage vault not found. Run data generator first.")
        return

    print("Connection established...")
    print("RECOVERED DATA:")

    content = file.read()
    print(content.strip())

    file.close()
    print("Data recovery complete. Storage unit disconnected.")


if __name__ == "__main__":
    main()
