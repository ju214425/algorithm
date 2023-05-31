from collections import deque

def solution(maps):
    answer = -1
    
    visited = [[0 for _ in range(len(maps[0]))] for _ in range(len(maps))]
    
    d = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    
    cur = [0, 0]
    q = deque([cur])
    
    while q:
        x, y = q.popleft()
        print(x, y)
        if x == len(maps)-1 and y == len(maps[0])-1:
            break
            
        for dx, dy in d:
            nx, ny = x + dx, y + dy
            
            if not (0 <= nx and nx < len(maps) and 0 <= ny and ny < len(maps[0]) and visited[nx][ny] == 0 and maps[nx][ny] == 1):
                continue
            
            visited[nx][ny] = visited[x][y] + 1
            
            q.append([nx, ny])
    
    if visited[len(maps)-1][len(maps[0])-1] == 0 :
        answer = -1
    else:
        answer = visited[len(maps)-1][len(maps[0])-1]+1
    
    
    return answer