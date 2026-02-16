def lead_to_gold() -> str:
    from alchemy.elements import create_fire

    fire_result = create_fire()
    return f"Lead transmuted to gold using {fire_result}"


def stone_to_gem() -> str:
    from alchemy.elements import create_earth

    earth_result = create_earth()
    return f"Stone transmuted to gem using {earth_result}"
