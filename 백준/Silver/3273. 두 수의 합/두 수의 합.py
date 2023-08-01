n = int(input())
num = list(map(int, input().split()))
x = int(input())
cnt = 0

num.sort()

def bsearch(l, r, target, num):
    if i * 2 == x or l > r:return 0
    m = (l + r) // 2
    if num[m] == target:
        return 1
    elif num[m] > target:
        return bsearch(l, m-1, target, num)
    else:
        return bsearch(m+1, r, target, num)


for i in num:
    cnt += bsearch(0, len(num)-1, x - i, num)

print(cnt//2)