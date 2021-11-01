def grade(score):
    if score > 100 or score < 0:
        print('점수: %.1f, 학점: 잘못 입력함' % score)
    elif score >= 90:
        print('점수: %.1f, 학점: A' % score)
    elif score >= 80:
        print('점수: %.1f, 학점: B' % score)
    elif score >= 70:
        print('점수: %.1f, 학점: C' % score)
    elif score >= 60:
        print('점수: %.1f, 학점: D' % score)
    else:
        print('점수: %.1f, 학점: F' % score)

grade(float(input('점수를 입력하세요: ')))