weight = float(input('체중을 입력하세욮(kg): '))
height = float(input('신장을 입력하세요(cm): '))
bmi = weight / (height / 100) ** 2
print('BMI는', bmi, '입니다.')
if bmi < 18.5:
    print('나의 BMI는 저체중입니다.')
elif bmi < 23:
    print('나의 BMI는 정상입니다.')
elif bmi < 25:
    print('나의 BMI는 과체중입니다.')
elif bmi < 30:
    print('나의 BMI는 비만입니댜.')
else:
    print('나의 BMI는 고도비만입니다.')