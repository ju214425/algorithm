from collections import deque

n = int(input())

arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

h = max(max(arr))
w = 0

answer = 0

dx = [0, 0, 1, -1]
dy = [1, -1, 0 ,0]

while w <= h:
    temp = 0
    s = [[0]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if w < arr[i][j] and s[i][j] == 0:
                q = deque()
                q.append((i, j))
                s[i][j] = 1
                while q:
                    fx, fy = q.popleft()
                    # print(fx, fy)
                    for k in range(4):
                        nx = fx + dx[k]
                        ny = fy + dy[k]
                        
                        if 0 <= nx and nx < n and 0 <= ny and ny < n and s[nx][ny] == 0 and w < arr[nx][ny]:
                            s[nx][ny] = 1
                            q.append((nx, ny))
                            
                temp += 1
    
    answer = max(answer, temp)
    w += 1
    
print(answer)