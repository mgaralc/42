def ft_water_reminder():
    n = int(input("Days since last watering: "))
    if n > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
