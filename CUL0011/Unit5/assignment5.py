import random
start = int(input('범위의 시작 값을 입력하세요.\n'))
end = int(input('범위의 끝 값을 입력하세요.\n'))
num  = random.randint(start, end)
print('%d부터 %d까지 범위에서 선택된 로또 번호는 %d입니다.' % (start, end, num))