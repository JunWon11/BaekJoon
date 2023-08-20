import sys
input = sys.stdin.readline

n = int(input())

t = [0] * 36
t[0] = 1
for i in range(1, 36):
    for j in range(0, 35):
        t[i] += t[j] * t[i-1-j]

print(t[n])