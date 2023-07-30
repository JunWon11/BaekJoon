import sys

s = sys.stdin.readline().strip()
stack = []

for i in range(len(s)):
    if s[i] == "(":
        stack.append(s[i])
    elif s[i] == ")":
        cnt = 0
        while 1:
            tmp = stack.pop()
            if tmp == "(":
                break
            cnt += tmp
        stack.append(int(stack.pop()) * cnt)
    elif i < len(s) - 1 and s[i + 1] == "(":
        stack.append(int(s[i]))
    else:
        stack.append(1)

result = 0

for k in stack:
    result += k
print(result)