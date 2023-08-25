from collections import deque
from copy import deepcopy
import sys
input = sys.stdin.readline

def bfs(x, y, graph, visited):
    q = deque()
    q.append((x, y))
    while q:
        v = q.popleft()
        x, y = v
        c = graph[x][y]
        graph[x][y] = 0
        visited[x][y] = 1
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == c and visited[nx][ny] == 0:
                    q.append((nx, ny))
    return 1

n = int(input())
graph = []
visited = [[0 for i in range(n)] for i in range(n)]
svisited = deepcopy(visited)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(n):
    graph.append(list(input().rstrip()))

sgraph = deepcopy(graph)
for i in range(n):
    for j in range(n):
        if sgraph[i][j] == 'G':sgraph[i][j] = 'R'

cnt = 0
ccnt = 0

for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            cnt += bfs(i, j, graph, visited)

for i in range(n):
    for j in range(n):
        if sgraph[i][j] != 0:
            ccnt += bfs(i, j, sgraph, svisited)

print(cnt, end=' ')
print(ccnt)