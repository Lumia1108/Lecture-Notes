# Q1
install.packages('ggplot2')
library(ggplot2)
k = 100
y = c()
for(i in 1:200){
    y = append(y, max(i - k, 0))
}
df = data.frame(St=1:200, y)
ggplot(data=df, aes(x=St, y=y))+geom_line()

# Q2
BSM = function(s, t, k, v, r) {
    d1 = (log(s / k) + (r + v * v * 0.5) * t) / v * sqrt(t)
    d2 = d1 - v * sqrt(t)
    C = s * pnorm(d1, mean = 0, sd = 1) - k * exp(-r * t) * pnorm(d2, mean = 0, sd = 1)
    return(C)
}
print(BSM(100, 100, 0.5, 0.1, 0.04))

# Q3
rf <- 0.04
T <- 0.5
M <- 500
dt <- T/M
N <- 10000
S0 <- 100
K <- 100
sigma <- 0.1

# 한칼럼이 하나이 시계열 경로
# 행의 숫자는 시계열의 수
# 칼럼의 숫자는 시뮬레이션 횟수
sim_S = matrix(0, nrow=501, ncol=N)
sim_S[1,] = S0
for(nn in 1:N) {
    for(t in 1:M) {
        sim_S[t+1, nn] = sim_S[t, nn] * exp((rf - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * rnorm(1))
    }
}
sim_BSM = matrix(0, nrow=501, ncol=N)
for(nn in 1:N) {
    for(t in 1:M+1) {
        sim_BSM[t, nn] = BSM(sim_S[t, nn], 100, 0.5, 0.1, 0.04)
    }
}
print(sim_BSM)
sim_V = c()
sum_V = 0
for(nn in 1:N) {
    value = max(sim_S[501, nn] - K, 0)
    sim_V[nn] = value
    sum_V = sum_V + value
}
sim_C = exp((-rf * T) / N) * sum_V
print(sim_C)
df2 = data.frame(x=1:501)
df2$y1 = sim_S[,1]
df2$y2 = sim_S[,2]
df2$y3 = sim_S[,3]
df2$y4 = sim_S[,4]
df2$y5 = sim_S[,5]
ggplot(data=df2, aes(x=x, y=y1))+geom_line()
ggplot(data=df2, aes(x=x, y=y2))+geom_line()
ggplot(data=df2, aes(x=x, y=y3))+geom_line()
ggplot(data=df2, aes(x=x, y=y4))+geom_line()
ggplot(data=df2, aes(x=x, y=y5))+geom_line()
