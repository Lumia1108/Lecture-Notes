# Term Project for Probability & Statistics
import numpy as np
import matplotlib.pyplot as plt
import math
from sklearn.linear_model import LinearRegression

# Generation of RVs
X = np.random.normal(loc=4, scale=5, size=(2000))
a1, b1 = map(int, input("Input a b : ").split())
Z1 = np.random.normal(loc=0, scale=1, size=(2000))
Y1 = []
for i in range(2000):
    Y1.append(a1 * X[i] + b1 + Z1[i] * math.exp((-(X[i]-4) ** 2)/50))
Z2 = np.random.normal(loc=0, scale=3, size=(2000))
Y2 = []
for i in range(2000):
    Y2.append(a1 * X[i] + b1 + Z2[i] * math.exp((-(X[i]-4) ** 2)/50))

# 산점도 보여주기
print("X-Y1 graph is here. (see picture in new window)")
plt.scatter(X, Y1, alpha=0.5)
plt.title('X-Y1')
plt.xlabel('X')
plt.ylabel('Y1')
plt.show()
print()

print("X-Y2 graph is here. (see picture in new window)")
plt.scatter(X, Y2, alpha=0.5)
plt.title('X-Y2')
plt.xlabel('X')
plt.ylabel('Y2')
plt.show()
print()

# X와 Y1, Y2의 CorrCoef 출력
print("X-Y1 Correlation Coefficient")
print(np.corrcoef(X, Y1)[0, 1])
print("X-Y2 Correlation Coefficient")
print(np.corrcoef(X, Y2)[0, 1])

print()

# Estimation X-Y1
line_fitter = LinearRegression()
line_fitter.fit(X.reshape(-1, 1), Y1)
predicted_a = line_fitter.coef_
predicted_b = line_fitter.intercept_
X_new = np.random.normal(loc=4, scale=5, size=(200))
predicted_Y1 = []
real_Y1 = []
for i in range(200):
    predicted_Y1.append(predicted_a * X_new[i] + predicted_b)
    real_Y1.append(a1 * X_new[i] + b1 + Z1[i] * math.exp((-(X_new[i]-4) ** 2)/50))
squared_error = 0
for i in range(200):
    squared_error += (predicted_Y1[i] - real_Y1[i]) ** 2

print('mean squared error of X-Y1 prediction')
print(squared_error/200)

# Estimation X-Y2
line_fitter = LinearRegression()
line_fitter.fit(X.reshape(-1, 1), Y2)
predicted_a = line_fitter.coef_
predicted_b = line_fitter.intercept_
X_new = np.random.normal(loc=4, scale=5, size=(200))
predicted_Y2 = []
real_Y2 = []
for i in range(200):
    predicted_Y2.append(predicted_a * X_new[i] + predicted_b)
    real_Y2.append(a1 * X_new[i] + b1 + Z2[i] * math.exp((-(X_new[i]-4) ** 2)/50))
squared_error = 0
for i in range(200):
    squared_error += (predicted_Y2[i] - real_Y2[i]) ** 2

print('mean squared error of X-Y2 prediction')
print(squared_error/200)