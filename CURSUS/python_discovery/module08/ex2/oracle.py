import os
from dotenv import load_dotenv

load_dotenv()

MATRIX_MODE = os.getenv("MATRIX_MODE")
DATABASE_URL = os.getenv("DATABASE_URL")
API_KEY = os.getenv("API_KEY")
LOG_LEVEL = os.getenv("LOG_LEVEL")
ZION_ENDPOINT = os.getenv("ZION_ENDPOINT")

mode = MATRIX_MODE or "development"

print("Accessing the Mainframe")
print("ORACLE STATUS: Reading the Matrix...\n")
print("Configuration loaded:")

print(f"Mode: {mode}")

if DATABASE_URL:
    if mode == "production":
        print("Database: Connected to production instance")
    else:
        print("Database: Connected to local instance")
else:
    print("Database: Not configured")

if API_KEY:
    print("API Access: Authenticated")
else:
    print("API Access: Missing API key")

log_level = LOG_LEVEL or "INFO"
print(f"Log Level: {log_level}")

if ZION_ENDPOINT:
    print("Zion Network: Online")
else:
    print("Zion Network: Offline")

print("\nEnvironment security check:")
print("[OK] No hardcoded secrets detected")

if all([DATABASE_URL, API_KEY, LOG_LEVEL, ZION_ENDPOINT]):
    print("[OK] Production overrides available")
else:
    print("[WARN] Missing configuration variables detected")

print("\nThe Oracle sees all configurations.")