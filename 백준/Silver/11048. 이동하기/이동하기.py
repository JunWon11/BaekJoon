import sys
input = sys.stdin.readline

n, m = map(int, input().split())
miro = []
for i in range(n):
    miro.append(list(map(int, input().split())))
    miro[i].insert(0, 0)

miro.insert(0, [0] * (m+1))
for i in range(1, n+1):
    for j in range(1, m+1):
        miro[i][j] += max(miro[i-1][j], miro[i][j-1], miro[i-1][j-1])

print(miro[n][m])