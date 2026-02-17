if __name__ == "__main__":
    players = [
        {"name": "alice", "score": 2300, "active": True},
        {"name": "bob", "score": 1800, "active": True},
        {"name": "charlie", "score": 2150, "active": True},
        {"name": "diana", "score": 2050, "active": False},
    ]

    player_achievements = {
        "alice": [
            "first_kill",
            "level_10",
            "boss_slayer",
            "first_kill",
            "level_10",
        ],
        "bob": [
            "first_kill",
            "level_10",
            "first_kill",
        ],
        "charlie": [
            "boss_slayer",
            "level_10",
            "first_kill",
            "first_kill",
            "level_10",
            "boss_slayer",
            "level_10",
        ],
        "diana": [
            "first_kill",
            "level_10",
        ],
    }

    events = [
        {"region": "north", "active": True},
        {"region": "east", "active": True},
        {"region": "central", "active": True},
        {"region": "north", "active": True},
        {"region": "west", "active": False},
    ]

    print("=== Game Analytics Dashboard ===")

    print("\n=== List Comprehension Examples ===")

    high_scorers = [
        player["name"]
        for player in players
        if player["score"] > 2000
    ]
    print(f"High scorers (>2000): {high_scorers}")

    doubled_scores = [
        player["score"] * 2
        for player in players
    ]
    print(f"Scores doubled: {doubled_scores}")

    active_players = [
        player["name"]
        for player in players
        if player["active"]
    ]
    print(f"Active players: {active_players}")

    print("\n=== Dict Comprehension Examples ===")

    player_scores = {
        player["name"]: player["score"]
        for player in players
        if player["name"] != "diana"
    }
    print(f"Player scores: {player_scores}")

    score_categories = {
        "high": sum(
            [
                1
                for player in players
                if player["score"] >= 2100
            ]
        ),
        "medium": sum(
            [
                1
                for player in players
                if 1900 <= player["score"] < 2100
            ]
        ),
        "low": sum(
            [
                1
                for player in players
                if player["score"] < 1900
            ]
        ),
    }
    print(f"Score categories: {score_categories}")

    achievement_counts = {
        player_name: len(player_achievements[player_name])
        for player_name in player_achievements
    }
    print(f"Achievement counts: {achievement_counts}")

    print("\n=== Set Comprehension Examples ===")

    unique_players = {
        player["name"]
        for player in players
    }
    print(f"Unique players: {unique_players}")

    unique_achievements = {
        achievement
        for player_name in player_achievements
        for achievement in player_achievements[player_name]
    }
    print(f"Unique achievements: {unique_achievements}")

    active_regions = {
        event["region"]
        for event in events
        if event["active"]
    }
    print(f"Active regions: {active_regions}")

    print("\n=== Combined Analysis ===")

    total_players = len(players)
    print(f"Total players: {total_players}")

    total_unique_achievements = len(unique_achievements)
    print(f"Total unique achievements: {total_unique_achievements}")

    scores = [
        player["score"]
        for player in players
    ]
    average_score = sum(scores) / len(scores)
    print(f"Average score: {average_score}")

    top_score = max(scores)

    top_name = [
        player["name"]
        for player in players
        if player["score"] == top_score
    ][0]

    top_achievements = len(player_achievements[top_name])

    print(
        f"Top performer: {top_name} "
        f"({top_score} points, "
        f"{top_achievements} achievements)"
    )
