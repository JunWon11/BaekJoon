from collections import deque
from copy import deepcopy
import sys
input = sys.stdin.readline

def bfs(a, b):
    q = deque()
    q.append((a, b))
    while q:
        v = q.popleft()
        x, y = v
        graph[x][y] = 0
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 1:
                q.append((nx, ny))
                graph[nx][ny] = 0

    return 1
        

T = int(input())
dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
for i in range(T):
    m, n, k = map(int, input().split())
    graph = [[0 for a in range(m)]for b in range(n)]
    for j in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1
    cnt = 0
    for j in range(n):
        for l in range(m):
            if graph[j][l] == 1:
                cnt += bfs(j, l)
    print(cnt)