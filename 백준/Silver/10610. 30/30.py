N = list(map(int, input()))

if sum(N) % 3 != 0 or 0 not in N:print(-1)
else:
    N.sort(reverse=True)
    for _ in N:
        print(_, end='')