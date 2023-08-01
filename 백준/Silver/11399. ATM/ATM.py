n = int(input())

a = list(map(int, input().split()))

a.sort()

result = 0

for i in range(len(a)):
    result += (len(a) - i) * a[i]

print(result)