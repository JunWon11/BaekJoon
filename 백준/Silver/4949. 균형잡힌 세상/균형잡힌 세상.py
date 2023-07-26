import sys
input = sys.stdin.readline

while(1):
    flag = 1
    stack = []
    s = input().rstrip()
    if s == ".": break
    for _ in s:
        if _ == '(' or _ == '{' or _ == '[':
            stack.append(_)
        elif _ == ')':
            if not stack:
                flag = 0
                break
            if stack.pop() != '(': flag = 0
        elif _ == '}':
            if not stack:
                flag = 0
                break
            if stack.pop() != '{': flag = 0
        elif _ == ']':
            if not stack:
                flag = 0
                break
            if stack.pop() != '[': flag = 0
        if flag == 0:break
    if stack : flag = 0
    if flag == 0:print("no")
    else: print("yes")