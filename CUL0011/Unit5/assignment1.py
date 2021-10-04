midterm = float(input('중간고사 점수 입력: '))
final = float(input('기말고사 점수 입력: '))
average = (midterm + final) / 2

if average < 80:
    print('당신의 점수는 %.2f이며, 불합격입니다.' % average)
else:
    print('당신의 점수는 %.2f이며, 합격입니다.' % average)