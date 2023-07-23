import sys
input = sys.stdin.readline
a = []
n = int(input())
cnt = 1
for _ in range(n):
    a.append(int(input()))
max = a.pop()
while a:
    k = a.pop()
    if k > max : 
        cnt += 1
        max = k
print(cnt)