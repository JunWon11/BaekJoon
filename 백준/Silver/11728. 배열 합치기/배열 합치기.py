n,m = map(int, input().split())

list_1 = list(map(int, input().split()))
list_2 = list(map(int, input().split()))

list_1 += list_2
list_1.sort()

for i in list_1:
    print(i, end=' ')