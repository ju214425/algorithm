from collections import defaultdict

n = int(input())

arr = list(map(int, input().split()))

p1 = 0
p2 = 0
answer = 0
d = defaultdict(int)

while p1 < n and p2 < n:
    d[arr[p2]] += 1
    p2 += 1
    
    while len(d) > 2:
        d[arr[p1]] -= 1
        if d[arr[p1]] == 0:
            del d[arr[p1]]
        p1 += 1
        
    answer =  max(p2 - p1, answer)
    
print(answer)
            