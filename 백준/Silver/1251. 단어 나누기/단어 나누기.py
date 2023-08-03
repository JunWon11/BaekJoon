s = input()

result = 'z' * len(s)

for i in range(1, len(s)-1):
    for j in range(i+1, len(s)):
        tmp = s[:i][::-1] + s[i:j][::-1] + s[j:][::-1]
        result = min(result, tmp)

print(result)