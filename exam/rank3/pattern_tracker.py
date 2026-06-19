def Pattern_tracker(s: str) -> int:
    count = 0
    for i in range(1, len(s)):
        if s[i].isdigit() and s[i-1].isdigit():
            if int(s[i]) == int(s[i-1])+1:
                count += 1
    return count
