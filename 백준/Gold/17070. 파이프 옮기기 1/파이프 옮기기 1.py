n = int(input())

arr = [list(map(int, input().split())) for i in range(n)]
dp = list()
for i in range(n):
    temp = list()
    for j in range(n):
        temp.append([0, 0, 0])        
    dp.append(temp)
    
dp[0][1][0] = 1    

for i in range(2, n):
    if arr[0][i] == 1:
        break
    dp[0][i][0] = dp[0][i-1][0]

for i in range(1, n):
    for j in range(1, n):
        # 현재 위치 체크
        if arr[i][j] == 1:
            dp[i][j][0] = 0
            dp[i][j][1] = 0
            dp[i][j][2] = 0
            continue
        
        dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
        dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
        if arr[i-1][j] == 1 or arr[i][j-1] == 1 :
            dp[i][j][2] = 0
        else:
            dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]

print(sum(dp[n-1][n-1]))