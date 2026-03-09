def spell_combiner(spell1: callable, spell2: callable) -> callable:
    def combined(*args, **kwargs):
        result1 = spell1(*args, **kwargs)
        result2 = spell2(*args, **kwargs)
        return (result1, result2)

    return combined


def power_amplifier(base_spell: callable, multiplier: int) -> callable:
    def amplifier(*args, **kwargs):
        return base_spell(*args, **kwargs) * multiplier

    return amplifier


def conditional_caster(condition: callable, spell: callable) -> callable:
    def caster(*args, **kwargs):
        if condition(*args, **kwargs):
            return spell(*args, **kwargs)
        else:
            return "Spell fizzled"

    return caster


def spell_sequence(spells: list[callable]) -> callable:
    def sequence(*args, **kwargs):
        return [spell(*args, **kwargs) for spell in spells]

    return sequence
