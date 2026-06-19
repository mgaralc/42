def sculptor(text: str) -> str:
    minus = text.lower()
    new = ""
    letter_count = 0
    for c in minus:
        if c.isalpha():
            if letter_count % 2 == 0:
                new += c
            else:
                new += c.upper()
            letter_count += 1
        else:
            new += c
    return new

if __name__ == "__main__":
    print(sculptor("Hello world"))
