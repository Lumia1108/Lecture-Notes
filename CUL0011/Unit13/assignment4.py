numbers = list(range(1, 10))
output = [[], [], []]
for num in numbers:
    output[num % 3 - 1].append(num)

print(output)