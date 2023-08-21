import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * n
pd = []

for i in range(n):
    pd.append(int(input()))

dp[0] = pd[0]
if n > 1:
    dp[1] = pd[0] + pd[1]
if n > 2:
    dp[2] = max(pd[0] + pd[1], pd[0]+pd[2], pd[1] + pd[2])

for i in range(3, n):
    dp[i] = max(dp[i-3] + pd[i]+ pd[i-1], dp[i-2] + pd[i])
    dp[i] = max(dp[i], dp[i-1])
print(max(dp))