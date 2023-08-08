import sys
input = sys.stdin.readline

n = int(input())

stair = []
dp = [0] * n

for i in range(n):
    stair.append(int(input()))

cnt = 0
if len(stair) <= 2:print(sum(stair))
else:
    dp[0] = stair[0]
    dp[1] = stair[0] + stair[1]
    for i in range(2, n):
        dp[i] = max(dp[i-3] + stair[i-1] + stair[i], dp[i-2] + stair[i])
    print(dp[-1])