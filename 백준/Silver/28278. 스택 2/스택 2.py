import sys
input = sys.stdin.readline

stack = []
n = int(input())

for i in range(n):
    s = input().rstrip()
    if s[0] == '1':stack.append(s[2:])
    elif s[0] == '2':
        if stack:print(stack.pop())
        else:print(-1)
    elif s[0] == '3':
        print(len(stack))
    elif s[0] == '4':
        if stack:print(0)
        else:print(1)
    elif s[0] == '5':
        if stack:print(stack[len(stack)-1])
        else:print(-1)