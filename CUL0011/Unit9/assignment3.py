def isEven(n):
    return n % 2 == 0

num = int(input('정수를 입력하세요: '))
if isEven(num):
    print('입력한 %d는(은) 짝수입니다.' % num)
else:
    print('입력한 %d는(은) 홀수입니다.' % num)