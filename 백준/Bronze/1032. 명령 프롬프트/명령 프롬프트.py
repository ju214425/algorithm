n = int(input())

arr = []

answer = ''

for i in range(n):
    arr.append(input())

for i in range(len(arr[0])):
    c = arr[0][i]
    for j in range(1, n):
        if c != arr[j][i]:
            answer += '?'
            break
    else:
        answer += c

print(answer)
    