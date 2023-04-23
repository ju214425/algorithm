from collections import deque
from itertools import combinations as C
from copy import *

n, m = map(int, input().split())
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
graph = []
zeroList = []
twoList = []
answer = 0

def bfs(fx, fy, g, v):
    q = deque()
    
    q.append([fx, fy])
    v[fx][fy] = 1
    g[fx][fy] = 2
    
    while q:
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m and v[nx][ny] == 0 and g[nx][ny] == 0:
                q.append([nx, ny])
                v[nx][ny] = 1

def check(g, v):
    safe = 0
    for i in range(n):
        for j in range(m):
            if v[i][j] == 0 and g[i][j] == 0:
                safe += 1
                
    return safe

for _ in range(n):
    graph.append(list(map(int, input().split())))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            zeroList.append([i, j])
        if graph[i][j] == 2:
            twoList.append([i, j])
            
for item in list(C(zeroList, 3)):
    g = deepcopy(graph)
    v = [[0] * m for _ in range(n)]
    
    for wall in item:
        x, y = wall
        g[x][y] = 1
        
    for t in twoList:
        x2, y2 = t
        bfs(x2, y2, g, v)

    answer = max(answer, check(g, v))
    
    for wall in item:
        w, y = wall
        g[x][y] = 0

print(answer)
        