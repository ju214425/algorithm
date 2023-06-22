n, k = map(int, input().split())

arr = []
dp = [0] * (k+1)

for _ in range(n):
    arr.append(int(input()))
    
for item in arr:
    for i in range(1, k+1):
        if i == item:
            dp[i] += 1
        elif i > item:
            dp[i] = dp[i] + dp[i-item]

print(dp[k])