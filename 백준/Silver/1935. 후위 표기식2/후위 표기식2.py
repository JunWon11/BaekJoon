import sys

input = sys.stdin.readline

n = int(input())
s = input().strip()
num_list = []
stack = []
result = 0

for i in range(n):
    num_list.append(int(input().strip()))
for _ in s:
    if _ >= 'A' and _ <= 'Z':
        stack.append(num_list[ord(_) - ord('A')])
    else:
        num2 = stack.pop()
        num1 = stack.pop()
        if _ == '+':
            result = num1 + num2
            stack.append(result)
        elif _ == '-':
            result = num1 - num2
            stack.append(result)
        elif _ == '*':
            result = num1 * num2
            stack.append(result)
        elif _ == '/':
            result = num1 / num2
            stack.append(result)
print("%.2f"%result)