s = input()

stack = []

for i in range(len(s)):
    if i < len(s) - 1 and s[i + 1] == '(':
        stack.append(int(s[i]))
    elif '0' <= s[i] <= '9':
        stack.append(1)
    elif s[i] == '(':
        stack.append(s[i])
    elif s[i] == ')':
        cnt = 0
        while 1:
            k = stack.pop()
            if k == '(':break
            cnt += k
        stack.append(int(stack.pop()) * cnt)

result = 0

for _ in stack:
    result += _
print(result)