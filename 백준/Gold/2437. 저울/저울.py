n = int(input())

arr = list(map(int, input().split()))

arr = sorted(arr)

value = arr[0]
answer = 0

for i in range(1, n):
    if value + 1 < arr[i]:
        answer = value + 1
        break
    
    value += arr[i]
else:
    answer = value + 1

if arr[0] != 1:
    answer = 1
    
print(answer)