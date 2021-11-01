import random
from typing import Counter
count = 0

while count < 5:
    num1 = random.randint(2, 9)
    num2 = random.randint(2, 9)
    mul = num1 * num2
    answer = input('%d * %d = ' % (num1, num2))
    if answer == str(mul):
        print('정답!')
        count += 1
    else:
        print('땡ㅋㅋㅋ')

print('통과!!')