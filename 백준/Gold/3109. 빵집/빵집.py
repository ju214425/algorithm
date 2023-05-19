r, c = map(int, input().split())

arr = [[0] * c for _ in range(r)]
visited = [[0] * c for _ in range(r)]
answer = 0

dx = [-1, 0, 1]

for i in range(r):
    temp = input()
    
    for j in range(c):
        arr[i][j] = temp[j]
        
def dfs(x, y):
    global answer
    
    if y == c-1:
        answer += 1
        return True

    for i in range(3):
        nx = x + dx[i]
        ny = y + 1
        
        if 0 <= nx < r and 0 <= ny < c and visited[nx][ny] == 0 and arr[nx][ny] == '.':
            
            visited[nx][ny] = 1
            if dfs(nx, ny):
                return True
    
    return False

for i in range(r):
    visited[i][0] = 1
    dfs(i, 0)

print(answer)