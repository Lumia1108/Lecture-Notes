import random
a = int(input('정수 입력: '))
b = int(input('정수 입력: '))

def lotto(n1, n2):
    return random.randint(min(n1, n2), max(n1, n2))

i = 6
result = '추천 로또 프로그램:'

while i > 0:
    result += ' %s' % str(lotto(a, b))
    i -= 1

print(result)