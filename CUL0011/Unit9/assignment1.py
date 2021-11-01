price = int(input('소비자 가격을 입력해주세요: '))
def getTax():
    print('물건가격: %.2f, 부가가치세: %.2f' % (price / 1.1, price / 11))
getTax()