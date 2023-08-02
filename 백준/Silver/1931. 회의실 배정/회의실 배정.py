n = int(input())

time = []

tmp = 0

cnt = 0

for i in range(n):
    time.append(list(map(int, input().split())))

time.sort(key= lambda x:(x[1], x[0]))

for i in time:
    if i[0] >= tmp:
        tmp = i[1]
        cnt += 1
print(cnt)