from pandas._libs.missing import NA
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import csv, os, re

# Q5
def opencsv(filename):
    f = open(filename, 'r', encoding='utf-8-sig')
    reader = csv.reader(f)
    output = []
    for i in reader:
        output.append(i)
    f.close()
    return output

def writecsv(filename, the_list):
    f = open(filename, 'w', encoding='utf-8-sig')
    writer = csv.writer(f, delimiter=',')
    writer.writerows(the_list)
    f.close()

data = opencsv('boston_csv.csv')
df = pd.DataFrame(data[1:], columns=data[0])
for i in data[0]:
    for j, value in enumerate(df[i]):
        if value == 'na':
            df[i][j] = NA
        elif value == 'NaN':
            df[i][j] = float('NaN')
print(df)
df = df.dropna()
df = df.astype('float')
print(df)

# Q6
print(df.describe()) 
corr = df.corr(method='pearson')
sns.heatmap(corr, cmap='viridis')
plt.show()
print()

# Q7
X = df['LSTAT']
Y = df['MEDV']
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.25, random_state=3)
lm = LinearRegression()
lm.fit(X_train.values.reshape(-1, 1), Y_train.values.reshape(-1, 1))
Yhat = lm.predict(X_train.values.reshape(-1, 1))
print(lm.coef_)
print(lm.intercept_)
print(r2_score(Y_train, Yhat))
print(mean_squared_error(Y_train, Yhat))
Yhat = lm.predict(X_test.values.reshape(-1, 1))
print(mean_squared_error(Y_test, Yhat))
print()

# Q8
lm=LinearRegression()
X = df[['LSTAT', 'TAX']] # Two Independent Variables
Y = df['MEDV']

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.25, random_state=3)
lm.fit(X_train, Y_train) #Fitting
Yhat=lm.predict(X_train) #Predicting
print(lm.intercept_)
print(lm.coef_)
print(r2_score(Y_train, Yhat))
print(mean_squared_error(Y_train,Yhat))
Yhat=lm.predict(X_test)
print(mean_squared_error(Y_test,Yhat))