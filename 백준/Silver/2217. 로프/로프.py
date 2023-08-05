import sys
input = sys.stdin.readline

N = int(input())
rope = []
max_w = 0

for i in range(N):
    rope.append(int(input()))
rope.sort()

for i in range(len(rope)):
    if rope[i] * (N - i) > max_w:
        max_w = rope[i] * (N - i)

print(max_w)