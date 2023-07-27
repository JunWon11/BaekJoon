import sys
input = sys.stdin.readline

stack = []
cnt = 0
s = input().rstrip()

for _ in s:
    if _ == '(':
        stack.append(_)
    else:
        if stack:
            stack.pop()
        else:
            cnt+=1

cnt += len(stack)
print(cnt)