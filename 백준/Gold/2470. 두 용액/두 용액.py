n = int(input())

solution = sorted(list(map(int, input().split())))

left = 0
right = n-1
two = [0, 0]
abs_min = 2000000000

while left < right:
    if abs(solution[left] + solution[right]) < abs_min:
        abs_min = abs(solution[left] + solution[right])
        two[0] = solution[left]
        two[1] = solution[right]
    if solution[left] + solution[right] < 0:
        left += 1
    else:
        right -= 1
        

two.sort()
for i in two:
    print(i, end=' ')