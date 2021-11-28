import random
color = ['black', 'grey', 'white', 'pink']
topwears = ['sweater', 'shirts', 'blouse', 'jacket']
bottomwears = ['skirt', 'pants', 'leggings', 'jeans']
accessory = ['hat', 'tie', 'scarf', 'shoes']

for i in range(3):
    print('오늘의 패선 %d번 추천 조합입니다.' % (i + 1))
    print(color[random.randint(0, len(color) - 1)], topwears[random.randint(0, len(topwears) - 1)])
    print(color[random.randint(0, len(color) - 1)], bottomwears[random.randint(0, len(bottomwears) - 1)])
    print(color[random.randint(0, len(color) - 1)], accessory[random.randint(0, len(accessory) - 1)])
    print()