def check():
    num = input('주민번호를 입력하세요(형태 xxxxxx-xxxxxxx): ')
    if len(num) == 14 and num[6] == '-':
        return True
    else:
        return False

while True:
    if check():
        break
    else:
        print('잘못입력했습니다.')