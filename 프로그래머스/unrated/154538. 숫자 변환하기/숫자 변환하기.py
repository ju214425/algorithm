from collections import deque

def solution(x, y, n):
    answer = -1
    
    q = deque()
    
    q.append([x, 0])
    
    v = {}
    v[x] = True
    
    while q:
        front = q.popleft()
        if front[0] == y:
            answer = front[1]
            break
            
        if front[0] * 2 <= y and front[0] * 2 not in v:
            q.append([front[0] * 2, front[1] + 1])
            v[front[0] * 2] = True
            
        if front[0] * 3 <= y and front[0] * 3 not in v:
            q.append([front[0] * 3, front[1] + 1])
            v[front[0] * 3] = True
            
        if front[0] + n <= y and front[0] + n not in v:
            q.append([front[0] + n, front[1] + 1])
            v[front[0] + n] = True
    
    return answer