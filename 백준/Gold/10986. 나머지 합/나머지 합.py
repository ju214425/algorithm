n, m = map(int, input().split())

arr = list(map(int, input().split()))

mod = [0] * m
mod[0] = 1
mod[arr[0] % m] += 1 

answer = 0

for i in range(1, len(arr)):
    arr[i] += arr[i-1]
    mod[arr[i] % m] += 1
    
for m in mod:
    if m >= 2:
        answer += (m*(m-1))//2
        
print(answer)