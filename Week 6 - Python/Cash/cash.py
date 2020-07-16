from cs50 import get_float

change = get_float("Change owed: ")

count = 0
while True:
    if change >= .25:
        count += 1
        change -= .25
    elif change >= .10:
        count += 1
        change -= .10
    elif change >= .05:
        count += 1
        change -= .05
    elif change > 0:
        count += 1
        change -= .01
    else:
        break

print(count)
