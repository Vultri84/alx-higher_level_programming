#!/usr/bin/python3

import random
number = random.randint(-10, 10)

if number > 0:
    output = f"{number} is positive"
elif number == 0:
    output = f"{number} is zero"
else:
    output = f"{number} is negative"
print(output)
