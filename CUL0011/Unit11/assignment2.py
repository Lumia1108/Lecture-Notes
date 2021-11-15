def check(num):
    print('주민번호: %s' % num)
    if int(num[7]) % 2 == 1:
        print('당신은 남자이군요.')
    else:
        print('당신은 여자이군요.')

check(input('주민번호를 입력하세요(형태 xxxxxx-xxxxxxx): '))