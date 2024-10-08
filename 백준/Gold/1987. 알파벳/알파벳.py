r, c = map(int, input().split())
graph = [input() for _ in range(r)]

d = [0] * 26
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

answer = 0

def dfs(x, y, cnt):
    global answer
    
    answer = max(answer, cnt)
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        
        if 0 <= nx < r and 0 <= ny < c and d[ord(graph[nx][ny]) - ord('A')] == 0:
            d[ord(graph[nx][ny]) - ord('A')] = 1
            dfs(nx, ny, cnt+1)
            d[ord(graph[nx][ny]) - ord('A')] = 0

d[ord(graph[0][0]) - ord('A')] = 1

dfs(0, 0, 1)

print(answer)