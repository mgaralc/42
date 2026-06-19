def mergeList(list1: list, list2: list) -> list:
    if list1 is None and list2 is None:
        return []

    if list1 is None:
        return sorted(list2)

    if list2 is None:
        return sorted(list1)

    list1.extend(list2)

    return sorted(list1)

