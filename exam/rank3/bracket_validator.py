def bracket_validator(s: str) -> bool:
    stack = []

    for c in s:
        if c in "({[":
            stack.append(c)
        elif c in ")}]":
            if not stack:
                return False
            last = stack.pop()
            if c == ")" and last != "(":
                return False
            if c == "}" and last != "{":
                return False
            if c == "]" and last != "[":
                return False
    return not stack
