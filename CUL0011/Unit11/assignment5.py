import datetime
def age(num):
    print('주민번호:', num)
    now = int(datetime.datetime.now().strftime('%Y'))
    if int(num[7]) in [9, 0]:
        print('당신은 18%s에 태어났으며, %d살이군요.' % (num[0:2], (now - 1800 - int(num[0:2]) + 1)))
    elif int(num[7]) in [5, 6, 1, 2]:
        print('당신은 19%s에 태어났으며, %d살이군요.' % (num[0:2], (now - 1900 - int(num[0:2]) + 1)))
    else:
        print('당신은 19%s에 태어났으며, %d살이군요.' % (num[0:2], (now - 2000 - int(num[0:2]) + 1)))

age(input('주민번호를 입력하세요(형태 xxxxxx-xxxxxxx): '))