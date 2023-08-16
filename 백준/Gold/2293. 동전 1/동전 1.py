import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coins = []

dp = [0] * (k+1)
dp[0] = 1

for i in range(n):
    coins.append(int(input()))

coins.sort()

for i in coins:
    for j in range(1, k+1):
        if j >= i:
            dp[j] += dp[j-i]

print(dp[k])