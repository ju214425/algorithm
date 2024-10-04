from collections import defaultdict

n, d, k, c = map(int, input().split())

arr = [int(input()) for _ in range(n)]

sushi = defaultdict(int)

for i in range(k):
    sushi[arr[i]] += 1
    
sushi[c] += 1

ans = len(sushi)

for i in range(1, n):
    
    sushi[arr[i-1]] -= 1
    if sushi[arr[i-1]] == 0:
        del sushi[arr[i-1]]
        
    sushi[arr[(i+k-1)%n]] += 1
    
    ans = max(ans, len(sushi))

print(ans)