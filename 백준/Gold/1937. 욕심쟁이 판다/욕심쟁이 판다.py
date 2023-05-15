import sys
sys.setrecursionlimit(10**5)

n = int(input())

arr = []
dp = [[0] * n for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

answer = 0

for i in range(n):
    arr.append(list(map(int, input().split())))
    
def dfs(x, y):
    maxVal = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < n and 0 <= ny < n and arr[x][y] < arr[nx][ny]:
            if dp[nx][ny] == 0:
                dfs(nx, ny)
            maxVal = max(maxVal, dp[nx][ny])
            
    dp[x][y] = 1 + maxVal
    
for i in range(n):
    for j in range(n):
        if dp[i][j] == 0:
            dfs(i, j)

for i in range(n):
    for j in range(n):
        answer = max(answer, dp[i][j])
        
print(answer)