import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
board = []
queue = deque([])
visit = [[False] * m for _ in range(n)]
res = [[-1] * m for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for i in range(n):
    row = list(map(int, input().split()))

    for j in range(m):
        if row[j] == 2:
            queue.append((i, j))
            visit[i][j] = True
            res[i][j] = 0

        if row[j] == 0:
            res[i][j] = 0
            
    board.append(row)

while queue:
    x, y = queue.popleft()

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < n and 0 <= ny < m and not visit[nx][ny] and board[nx][ny] == 1:
            queue.append((nx, ny))
            visit[nx][ny] = True
            res[nx][ny] = res[x][y] + 1

for row in res:
    for i in row:
        print(i, end=" ")
    print()