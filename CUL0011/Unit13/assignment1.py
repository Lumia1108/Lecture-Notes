scores=[90, 25, 67, 45, 80]
for i, value in enumerate(scores):
    if value >= 60:
        print('%d번 학생은 %d점이며, 합격입니다.' % (i + 1, value))
    else:
        print('%d번 학생은 %d점이며, 불합격입니다.' % (i + 1, value))