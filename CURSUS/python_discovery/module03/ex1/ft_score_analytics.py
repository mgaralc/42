import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    argc = len(sys.argv)

    if argc == 1:
        print(
            "No scores provided. Usage: python3 ft_score_analytics.py "
            "<score1> <score2> ..."
        )
    else:
        scores = []
        i = 1
        try:
            for arg in sys.argv[i:]:
                scores.append(int(arg))
        except ValueError:
            print("Error: invalid score")
            sys.exit(1)
        print(f"Scores processed: {scores}")
        tscores = len(scores)
        print(f"Total players: {tscores}")
        media = 0
        for score in scores:
            media += score
        print(f"Total score: {media}")
        print(f"Average score: {media/tscores}")
        print(f"High score: {max(scores)}")
        print(f"Low score: {min(scores)}")
        print(f"Score range: {max(scores) - min(scores)}")
