from collections import deque

n, m = map(int, input().split())

graph = []

x = 0
y = 0
answer = 0
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
visited = [[False] * m for _ in range(n)]

for i in range(n):
    a = input()
    graph.append(a)
    for j in range(m):
        if 'I' == a[j]:
            x = i
            y = j

q = deque()
q.append((x, y))

while q:
    fx, fy = q.popleft()
    if graph[fx][fy] == 'P':
        answer += 1
    for i in range(4):
        nx = fx + dx[i]
        ny = fy + dy[i]
        
        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and graph[nx][ny] != 'X':
            visited[nx][ny] = True
            q.append((nx, ny))
            
if answer == 0:
    print('TT')
else:
    print(answer)