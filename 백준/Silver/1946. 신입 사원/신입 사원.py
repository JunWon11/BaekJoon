import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    N = int(input())
    app = []
    cnt = 0
    for j in range(N):
        app.append(list(map(int, input().split())))
    app.sort()
    min = app[0]
    for j in app:
        if j[1] <= min[1]:
            cnt += 1
            min = j
    print(cnt)