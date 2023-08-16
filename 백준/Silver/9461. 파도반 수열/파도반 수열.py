n=int(input())
p=[1,1,1]
for i in range(3,101):
    p.append(p[i-2]+p[i-3])
for i in range(n):
    print(p[int(input())-1])