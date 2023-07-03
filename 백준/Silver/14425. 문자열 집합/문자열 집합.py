n,m = map(int, input().split())
cnt = 0
s = []
for i in range(n):
  s.append(input())
s = set(s)
for i in range(m):
  str = input()
  if str in s: cnt+=1
print(cnt)