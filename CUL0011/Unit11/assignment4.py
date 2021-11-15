def isForeign(num):
    print('주민번호:', num)
    if int(num[7]) >= 5 and int(num[7]) <= 8:
        print('당신은 외국인이군요.')
    else:
        print('당신은 내국인이군요.')

isForeign(input('주민번호를 입력하세요(형태 xxxxxx-xxxxxxx): '))