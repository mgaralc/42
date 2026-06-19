def convert_base(num: str, from_base: int, to_base: int) -> str:
    base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    if from_base < 2 or from_base > 36:
        return "ERROR"

    if to_base < 2 or to_base > 36:
        return "ERROR"

    try:
        n = int(num, from_base)
    except ValueError:
        return "ERROR"
    
    if n == 0:
        return "0"
    
    res = ""

    while n > 0:
        res = res + base[n % to_base]
        n = n // to_base

    return res[::-1]
