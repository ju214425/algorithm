from collections import deque

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

idx = 1

while True:
    n = int(input())
    
    answer = 0
    
    if n == 0:
        break
    
    arr = [[0] * n for _ in range(n)]
    v = [[987654321] * n for _ in range(n)]
    
    q = deque()
    
    for i in range(n):
        a = input().split()
        for j in range(n):
            arr[i][j] = int(a[j])

    
    q.append([0, 0])
    v[0][0] = arr[0][0]
    
    while not len(q) == 0:
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < n and v[x][y] + arr[nx][ny] < v[nx][ny]:
                v[nx][ny] = v[x][y] + arr[nx][ny]
                q.append([nx, ny])
    
    print("Problem " + str(idx) + ": " + str(v[n-1][n-1]))
    
    idx += 1