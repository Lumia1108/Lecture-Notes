midterm = float(input('중간고사 점수 입력: '))
final = float(input('기말고사 점수 입력: '))
average = (midterm + final) / 2
absent = int(input('결석일수 입력: '))

if average >= 80 and absent < 6:
    print('당신의 점수는 %.2f이며, Pass입니다.' % average)
elif average >= 60 and absent < 6 :
    print('당신의 점수는 %.2f이며, 재시험 대상자입니다.' % average)
else:
    print('당신의 점수는 %.2f이며, Fail입니다.' % average)