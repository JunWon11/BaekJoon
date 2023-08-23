from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[0] * (m+1) for i in range(n+1)]
plus = [[1, 0], [0, 1], [-1, 0], [0, -1]]
q = deque()

for i in range(n):
    a = list(input().rstrip())
    for j in range(len(a)):
        graph[i][j] = int(a[j])

q.append([0, 0])
while q:
    v = q.popleft()
    x, y = v[0], v[1]
    
    for i in plus:
        nx, ny = x+i[0], y+i[1]
        if 0 <= nx < n and 0 <= ny < m:
            if  graph[nx][ny] == 1:
                q.append([nx, ny])
                graph[nx][ny] = graph[x][y] + 1

print(graph[n-1][m-1])