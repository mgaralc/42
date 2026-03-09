import time
from functools import wraps


def spell_timer(func: callable) -> callable:
    @wraps(func)
    def timer(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"Spell completed in {end - start} seconds")
        return result

    return timer


def power_validator(min_power: int) -> callable:
    pass


def retry_spell(max_attempts: int) -> callable:
    pass


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        pass


    def cast_spell(self, spell_name: str, power: int) -> str:
        pass
