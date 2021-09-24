weight = float(input('체중을 입력하세욮(kg): '))
height = float(input('신장을 입력하세요(cm): '))
bmi = weight / (height / 100) ** 2
print('BMI는', bmi, '입니다.')