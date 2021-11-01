import random
print('로또번호 생성기 프로그램')
for i in range(1, 7):
    print('%d번째 번호는 %d입니다.' % (i, random.randint(1, 45)))