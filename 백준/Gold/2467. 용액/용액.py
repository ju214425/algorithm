n = int(input())

arr = list(map(int, input().split()))

arr.sort()

p1 = 0
p2 = n-1
ans = abs(arr[p1] + arr[p2])
ans1 = 0
ans2 = n-1

while p1 < p2:
    val = arr[p1] + arr[p2]
    
    if abs(val) < ans:
        ans1 = p1
        ans2 = p2
        ans = abs(val)
        
        if abs == 0:
            break
        
    if val < 0:
        p1 += 1
    else:
        p2 -= 1
        
print(arr[ans1], arr[ans2])