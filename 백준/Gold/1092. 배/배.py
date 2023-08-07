import sys
input = sys.stdin.readline

n = int(input())
c_weight = list(map(int, input().split()))
m = int(input())
b_weight = list(map(int, input().split()))

c_weight.sort(reverse=True)
b_weight.sort(reverse=True)
cnt = 0

if c_weight[0] < b_weight[0]:cnt = -1
else:
    while b_weight:
        for i in range(n):
            for j in range(len(b_weight)):
                if c_weight[i] >= b_weight[j]:
                    b_weight.pop(j)
                    break
        cnt += 1

print(cnt)