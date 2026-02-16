def game_event_stream(n_events):
    names = ("alice", "bob", "charlie")
    actions = ("killed monster", "found treasure", "leveled up")

    for i in range(1, n_events + 1):
        name = names[(i - 1) % len(names)]
        action = actions[(i - 1) % len(actions)]
        level = i % 20 + 1
        yield (i, name, level, action)


def fibonacci():
    a = 0
    b = 1
    aux = 0
    ever = True

    while ever:
        yield a
        aux = a + b
        a = b
        b = aux


def isprime():
    a = 2
    while True:
        b = 2
        is_p = True

        while b * b <= a:
            if a % b == 0:
                is_p = False
                break
            b += 1

        if is_p:
            yield a

        a += 1


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")

    num = 1000
    print(f"Processing {num} game events...")

    total_events = 0
    high_level = 0
    treasure_events = 0
    level_up_events = 0

    for i, name, level, action in game_event_stream(num):
        total_events += 1

        if i <= 3:
            print(f"Event {i}: Player {name} (level {level}) {action}")
        elif i == 4:
            print("...")

        if level >= 10:
            high_level += 1
        if action == "found treasure":
            treasure_events += 1
        if action == "leveled up":
            level_up_events += 1

    print("=== Stream Analytics ===")
    print(f"Total events processed: {total_events}")
    print(f"High-level players (10+): {high_level}")
    print(f"Treasure events: {treasure_events}")
    print(f"Level-up events: {level_up_events}")
    print("Memory usage: Constant (streaming)")
    print("Processing time: N/A")

    print("\n=== Generator Demonstration ===")
    t_num = 10
    gen = fibonacci()

    print(f"Fibonacci sequence (first {t_num}): ", end="")
    for i in range(t_num):
        n = next(gen)
        if i > 0:
            print(", ", end="")
        print(n, end="")
    print()

    t_num = 5
    gen = isprime()
    print(f"Prime numbers (first {t_num}): ", end="")
    for i in range(t_num):
        n = next(gen)
        if i > 0:
            print(", ", end="")
        print(n, end="")
    print()
