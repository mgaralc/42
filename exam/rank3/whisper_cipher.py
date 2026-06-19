def Shift_alphabet(s: str, n: int) -> str:
    new = ""

    for i in s:
        if i >= "a" and i <= "z":
            new += chr((ord(i) - ord('a') + n) % 26 + ord('a'))
        elif i >= "A" and i <= "Z":
            new += chr((ord(i) - ord('A') + n) % 26 + ord('A'))
        else:
            new += i
    return new

