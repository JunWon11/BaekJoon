import sys
input = sys.stdin.readline

n = int(input())
result = 0
left_list = []
right_list = []

stick = []
for i in range(n):
    stick.append(list(map(int,input().split())))
    
stick = sorted(stick, key = lambda x:x[1])
max_stick = stick.pop()
for i in stick:
    if i[0] < max_stick[0]:left_list.append(i)
    else : right_list.append(i)

result += max_stick[1]
l_idx = max_stick[0]
r_idx = max_stick[0]
while left_list:
    l_stick = left_list.pop()
    if l_idx - l_stick[0] > 0:
        result += l_stick[1] * (l_idx - l_stick[0])
        l_idx = l_stick[0]

while right_list:
    r_stick = right_list.pop()
    if r_stick[0] - r_idx > 0:
        result += r_stick[1] * (r_stick[0] - r_idx)
        r_idx = r_stick[0]

print(result)