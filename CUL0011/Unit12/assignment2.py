numbers = [273, 103, 5, 32, 65, 9, 72, 8000, 99999]
for i in numbers:
    if i % 2 == 0:
        print('%d는 짝수이며, %d 자릿수입니다.' % (i, len(str(i))))
    else:
        print('%d는 홀수이며, %d 자릿수입니다.' % (i, len(str(i))))