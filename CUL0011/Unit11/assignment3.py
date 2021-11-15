def birthday(num):
    print('주민번호:', num)
    print('당신은 %s년 %s월 %s일에 태어났군요.' % (num[0:2], num[2:4], num[4:6]))

birthday(input('주민번호를 입력하세요(형태 xxxxxx-xxxxxxx): '))