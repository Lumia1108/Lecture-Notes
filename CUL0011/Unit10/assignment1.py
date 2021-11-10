def factorial(n):
    result = 1
    while n > 0:
        result *= n
        n -= 1
    return result

x = int(input('정수 입력: '))
print('%d! = %d' % (x, factorial(x)))