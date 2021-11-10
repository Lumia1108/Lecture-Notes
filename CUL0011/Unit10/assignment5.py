def orderA(a):
    a = a.upper()
    return ord(a) - 64

x = input('알파벳을 입력하세요: ')
print('입력한 %s는 알파벳 순서로 %d번째입니다.' % (x, orderA(x)))