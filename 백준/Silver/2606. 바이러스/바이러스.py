from collections import deque
import sys
input = sys.stdin.readline

def bfs(v):
    q = deque()
    q.append(v)
    while q:
        a = q.popleft()
        visited[a] = 1
        for i in range(n+1):
            if visited[i] == 0 and graph[a][i] == 1:
                q.append(i)

n = int(input())
m = int(input())
visited = [0] * (n+1)

graph = [[0 for i in range(n+1)] for j in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = graph[b][a] = 1

bfs(1)
print(sum(visited)-1)