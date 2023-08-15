import sys
input = sys.stdin.readline

n, m = map(int, input().split())
miro = []
for i in range(n):
    miro.append(list(map(int, input().split())))
miro.insert(0, [0] * m)
for i in range(1, n+1):
    for j in range(m):
        if j > 0:
            miro[i][j] += max(miro[i-1][j], miro[i][j-1], miro[i-1][j-1])
        else:
            miro[i][j] += miro[i-1][j] 

print(max(miro[n]))