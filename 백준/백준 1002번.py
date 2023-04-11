n=int(input())
for i in range(n):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    l=((x1-x2)**2+(y1-y2)**2)**0.5
    if l==0 and r1==r2:
        print(-1)
    elif abs(r1-r2)==l or r1+r2==l:print(1)
    elif abs(r1+r2)>l and abs(r1-r2)<l:print(2)
    else:print(0)