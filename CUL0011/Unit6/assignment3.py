import sys
password = ''
count = 0
while password != 'pythonisfun':
    if count == 5:
        print('로그인 실패')
    password = input('암호를 입력하세요\n')
    count += 1

print('로그인 성공')