import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split

# 1~2
wine = pd.read_csv('wine_data.csv')
print(wine.describe())

# 3
Y = wine.Class
X = wine.drop('Class', axis='columns')
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=3)

# 4~5
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, Y_train)
predict_value = list(knn.predict(X_train))
real_value = list(Y_train)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')

# 6
predict_value = list(knn.predict(X_test))
real_value = list(Y_test)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')

# 7
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train, Y_train)
predict_value = list(knn.predict(X_train))
real_value = list(Y_train)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')

knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train, Y_train)
predict_value = list(knn.predict(X_test))
real_value = list(Y_test)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')

# 8
Y = wine.Class
X = wine[['Alcohol', 'Malic acid', 'Ash', 'Alcalinity of ash']]
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=3)

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, Y_train)
predict_value = list(knn.predict(X_train))
real_value = list(Y_train)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')

predict_value = list(knn.predict(X_test))
real_value = list(Y_test)
err_value = 0
for i in range(len(predict_value)):
    if real_value[i] != predict_value[i]:
        err_value += 1
    else:
        pass
print(100 * err_value / len(predict_value), '%')