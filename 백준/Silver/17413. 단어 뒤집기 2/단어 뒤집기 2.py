s = input()
stack = []
clamp = []

for ch in s:
    if ch == '<':
        while stack:
            print(stack.pop(), end='')
        print(ch,end='')
        clamp.append(ch)
    elif ch == '>':
        for _ in stack:print(_, end='')
        stack = []
        print('>', end='')
        clamp.pop()
    elif ch == ' ' and not clamp:
        while stack:
            print(stack.pop(), end='')
        print(end=' ')
    else:
        stack.append(ch)
while stack:
    print(stack.pop(), end='')