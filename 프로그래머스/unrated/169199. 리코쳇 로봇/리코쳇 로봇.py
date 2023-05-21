from collections import deque

def solution(board):
    answer = -1
    
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    
    start = [0, 0]
    end = [0, 0]

    r = False
    g = False
    
    q = deque()
    visitedDict = {}
    
    for i in range(len(board)):
        if 'R' in board[i] and not r:
            start[0] = i
            start[1] = board[i].find('R')
            r = True
        
        if 'G' in board[i] and not g:
            end[0] = i
            end[1] = board[i].find('G')
            g = True
        
        if r and g:
            break
            
    def move(direction, x, y):
        nx, ny = x, y

        if direction == 0:
            for i in range(x, -1, -1):
                if board[i][y] == 'D':
                    break
                nx = i

        elif direction == 1:
            for i in range(x, len(board)):
                if board[i][y] == 'D':
                    break
                nx = i

        elif direction == 2:
            for i in range(y, len(board[0])):
                if board[x][i] == 'D':
                    break
                ny = i
        else:
            for i in range(y, -1, -1):
                if board[x][i] == 'D':
                    break
                ny = i

        return (nx, ny)
            
    x, y = start
    
    q.append((x, y))
    visitedDict[(x, y)] = 0
    
    while len(q) != 0:
        cx, cy = q.popleft()
        
        if (cx, cy) == tuple(end):
            answer = visitedDict[(cx, cy)]
            break
        
        for i in range(4):
            nx, ny = move(i, cx, cy)
            if (nx, ny) not in visitedDict:
                q.append((nx, ny))
                visitedDict[(nx, ny)] = visitedDict[(cx, cy)] + 1
                
    return answer