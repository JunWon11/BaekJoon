import sys
input = sys.stdin.readline

T = int(input())

for i in range(T):
    n = int(input())
    dp = []
    for j in range(2):
        dp.append(list(map(int, input().split())))
    if n > 1:
        dp[0][1] += dp[1][0]
        dp[1][1] += dp[0][0]
    for j in range(2, n):
        dp[0][j] += max(dp[1][j-1], dp[1][j-2])
        dp[1][j] += max(dp[0][j-1], dp[0][j-2])
    print(max(max(dp[0]), max(dp[1])))