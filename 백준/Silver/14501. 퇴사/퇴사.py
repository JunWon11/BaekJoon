import sys
input = sys.stdin.readline

n = int(input())
sangdam = []
dp = [0] * (n+1)
for i in range(n):
    sangdam.append(list(map(int, input().split())))
                   
for i in range(n):
    for j in range(i+sangdam[i][0], n+1):
        dp[j] = max(dp[i]+sangdam[i][1], dp[j])

print(dp[-1])