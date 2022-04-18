import math
import random
import matplotlib.pyplot as plt
from decimal import Decimal
import numpy as np

scope_n = 1000
p = 1 / scope_n
num = 25
data = []
exp_data = []
for i in range(1000):
    count = 0
    t = 0
    for j in range(1000):
        if random.randint(1, scope_n) == num:
            count += 1
            if t != 0: exp_data.append(j - t)
            t = j
    data.append(count)
mean_math = 1000 * p
ld = mean_math
mean_real = sum(data) / len(data)
exp_dist_math = [ld * math.exp(-ld * t) for t in range(1, 1001)]
exp_dist_cdf = [1 - math.exp(-ld * t) for t in range(1, 1001)]
pmf_math = []
pmf_real = []
for k in range(1001):
    pmf_real.append(data.count(k) / len(data)) # prob of real data
    pmf_math.append(Decimal(Decimal(math.exp(-mean_math)) * (Decimal(mean_math) ** Decimal(k))) / Decimal(math.factorial(k))) # mathematical prob
print((exp_data))
plt.plot(list(range(0, 1001)), pmf_math)
plt.title('Mathematical Poisson Distribution PMF')
plt.show()
plt.plot(list(range(0, 1001)), pmf_real)
plt.title('Poisson Distribution PMF with Real data')
plt.show()

exp_dist_real = [exp_data.count(i) / len(exp_data) for i in range(1, 1001)] # Normalization
exp_dist_real_cdf = [exp_dist_real[0] for i in range(len(exp_dist_real))]
print(len(exp_data))
for i in range(1, len(exp_dist_real_cdf)):
    exp_dist_real_cdf[i] = exp_dist_real_cdf[i - 1] + exp_dist_real[i]
plt.plot(list(range(1, 1001)), exp_dist_real_cdf)
plt.title('Exponential Distribution CDF with Real data')
plt.show()
plt.plot(list(range(1, 1001)), exp_dist_math)
plt.title('Mathematical Exponential Poisson Distribution PDF')
plt.show()
plt.plot(list(range(1, 1001)), exp_dist_cdf)
plt.title('Mathematical Exponential Poisson Distribution CDF')
plt.show()