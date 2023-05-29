from collections import deque
import math

def solution(progresses, speeds):
    answer = []
    
    q = deque()
    
    for i in range(len(speeds)):
        q.append(math.ceil((100 - progresses[i]) / speeds[i]))
    
    max_val = q[0]
    size = 0
    
    while q:
        f = q.popleft()
        if f <= max_val:
            size += 1
        else:
            answer.append(size)
            max_val = f
            size = 1
    
    answer.append(size)
    
    return answer