def isPalindrome(s: str) -> bool:
    c = ""
    mi = s.lower()
    for i in mi:
        if i.isalnum():
            c += i
    return c == c[::-1]
