from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    if graph[x][y] == 0:
        return -1
    else:
        cnt = 0
        graph[x][y] = 0
        q = deque()
        q.append((x,y))
        while q:
            x, y = q.popleft()
            cnt += 1
            for i in add:
                nx, ny = x+i[0], y+i[1]
                if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == 1:
                    graph[nx][ny] = 0
                    q.append((nx, ny))
        return cnt


add = [[1,0], [0,1], [-1,0], [0,-1]]
n = int(input())
graph = []

for i in range(n):
    s = [int(x) for x in input().rstrip()]
    graph.append(s)

cnt = []
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            cnt.append(bfs(i, j))

cnt.sort()
print(len(cnt))
for i in cnt:
    print(i)