from functools import reduce, partial, lru_cache, singledispatch
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    operations = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min
    }

    return reduce(operations[operation], spells)


def partial_enchanter(base_enchantment: callable) -> dict[str, callable]:
    fire_enchant = partial(base_enchantment, 50, "fire")
    ice_enchant = partial(base_enchantment, 50, "ice")
    lightning_enchant = partial(base_enchantment, 50, "lightning")

    return {
        "fire_enchant": fire_enchant,
        "ice_enchant": ice_enchant,
        "lightning_enchant": lightning_enchant
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> callable:

    @singledispatch
    def dispatch(spell):
        raise TypeError("Unsupported spell type")

    @dispatch.register
    def _(spell: int):
        return f"Damage spell with power {spell}"

    @dispatch.register
    def _(spell: str):
        return f"Enchantment spell: {spell}"

    @dispatch.register
    def _(spell: list):
        return [dispatch(s) for s in spell]

    return dispatch
