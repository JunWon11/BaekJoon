n = int(input())
for _ in range(1, n+1):
    a = list(input().split())
    print("Case #{}:".format(_), end=" ")
    while a:
        print(a.pop(),end=" ")