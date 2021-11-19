numbers = [273, 103, 5, 32, 65, 9, 72, 8000, 99999]
result = numbers[1]
for i in numbers:
    if result > i:
        result = i
print('min:', result)