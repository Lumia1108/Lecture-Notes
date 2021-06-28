import enum
import urllib.request as ur
from bs4 import BeautifulSoup as bs
from matplotlib.pyplot import figtext
import pandas as pd

# Q2
url = 'https://www.skysports.com/premier-league-table/2019'
html = ur.urlopen(url)
soup = bs(html.read(), 'html.parser')
table = soup.find('table', {"class": "standing-table__table callfn"})
headers = []
for i in table.find_all('th'):
    headers.append(i.text)
dic = {}
for i in headers:
    dic[i] = []
print(dic)
tbody = soup.find('tbody')
tr = tbody.find_all('tr')
for i, value in enumerate(tr):
    td = value.find_all('td')
    for j, data in enumerate(td):
        dic[headers[j]].append(data.text.strip())
df = pd.DataFrame(columns=headers)
for i in headers:
    df[i] = dic[i]
print(df)

# Q3
df = df.astype({'W': int, 'Pl': int, 'GD': int})
df['win_prob'] = df.W / df.Pl
print(df)

from sklearn.linear_model import LinearRegression
import numpy as np
X = df["GD"]
Y = df["win_prob"]
fitter = LinearRegression()
fitter.fit(X.values.reshape(-1, 1), Y)
print('a:', fitter.intercept_, 'b:', fitter.coef_[0])

# Q4
import statsmodels.api as sm
X2 = sm.add_constant(X)
est = sm.OLS(Y, X2)
est2 = est.fit()
print(est2.summary())