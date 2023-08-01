import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dx = []
bx = []
for i in range(n):
    dx.append(input().rstrip())
for i in range(m):
    bx.append(input().rstrip())

set1 = set(dx)
set2 = set(bx)

name = set1.intersection(set2)
name = list(name)
name.sort()

print(len(name))
for _ in name:
    print(_)