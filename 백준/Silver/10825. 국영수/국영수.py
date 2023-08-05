import sys
input = sys.stdin.readline

student = []
N = int(input())
for i in range(N):
    student.append(list(input().split()))
student.sort(key=lambda x:(-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in student:
    print(i[0])