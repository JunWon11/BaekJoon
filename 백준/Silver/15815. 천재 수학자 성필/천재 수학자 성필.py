s = input().rstrip()
stack = []
for _ in s:
    if '0' <= _ <= '9':
        stack.append(ord(_) - ord('0'))
    elif _ == '+':
        num2 = stack.pop()
        num1 = stack.pop()
        stack.append(num1 + num2)
    elif _ == '-':
        num2 = stack.pop()
        num1 = stack.pop()
        stack.append(num1 - num2)
    elif _ == '*':
        num2 = stack.pop()
        num1 = stack.pop()
        stack.append(num1 * num2)
    elif _ == '/':
        num2 = stack.pop()
        num1 = stack.pop()
        stack.append(num1 // num2)
print(stack.pop())