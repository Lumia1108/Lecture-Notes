def factorial(n1, n2):
    if n1-1 != 1:
        return factorial(n1 - 1, n2 * (n1 - 1))
    else:
        return n2

x = int(input('정수 입력: '))
print('%d! = %d' % (x, factorial(x, x)))