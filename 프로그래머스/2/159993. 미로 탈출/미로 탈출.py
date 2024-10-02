def solution(maps):
    answer = 0
    
    sx, sy = -1, -1
    lx, ly = -1, -1
    ex, ey = -1, -1
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    
    queue = list()
    visit = dict()
    
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == 'S':
                sx, sy = i, j
            elif maps[i][j] == 'L':
                lx, ly = i, j
            elif maps[i][j] == 'E':
                ex, ey = i, j
            
    queue.append((sx, sy, 0))
        
    while queue:
        front = queue.pop(0)
        visit[(front[0], front[1])] = True
        
        if (front[0], front[1]) == (lx, ly):
            answer += front[2]
            break
        
        for i in range(4):
            nx = front[0] + dx[i]
            ny = front[1] + dy[i]
            
            if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]) and maps[nx][ny] != 'X' and (nx, ny) not in visit:
                queue.append((nx, ny, front[2] + 1))
                visit[(nx, ny)] = True
    
    if answer == 0:
        return -1
    
    queue.clear()
    visit.clear()
    
    queue.append((lx, ly, 0))
    
    while queue:
        front = queue.pop(0)
        visit[(front[0], front[1])] = True
        
        if (front[0], front[1]) == (ex, ey):
            answer += front[2]
            return answer
            break
        
        for i in range(4):
            nx = front[0] + dx[i]
            ny = front[1] + dy[i]
            
            if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]) and maps[nx][ny] != 'X' and (nx, ny) not in visit:
                queue.append((nx, ny, front[2] + 1))
                visit[(nx, ny)] = True
            
    return -1