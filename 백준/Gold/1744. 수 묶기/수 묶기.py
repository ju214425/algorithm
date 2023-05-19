from collections import deque

n = int(input())
arr = []
marr = []

for i in range(n):
    k = int(input())
    if k > 0:
        arr.append(k)
    else:
        marr.append(k)
    
arr = sorted(arr, key = lambda x : (-x))
marr = sorted(marr)

answer = 0
p1 = 0
p2 = 1

while True:
    if p1 == len(arr)-1:
        answer += arr[p1]
        break
    
    if p1 > len(arr)-1:
        break
    
    if arr[p1] * arr[p2] > arr[p1] + arr[p2]:
        answer += (arr[p1] * arr[p2])
        p1 += 2
        p2 += 2
    
    else:
        answer += arr[p1]
        p1 += 1
        p2 += 1
        
p1 = 0
p2 = 1
        
while True:
    if p1 == len(marr)-1:
        answer += marr[p1]
        break
    
    if p1 > len(marr)-1:
        break
    
    if marr[p1] * marr[p2] > marr[p1] + marr[p2]:
        answer += (marr[p1] * marr[p2])
        p1 += 2
        p2 += 2
    
    else:
        answer += marr[p1]
        p1 += 1
        p2 += 1
        
print(answer)