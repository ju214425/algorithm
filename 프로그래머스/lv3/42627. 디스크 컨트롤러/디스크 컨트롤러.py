from heapq import *
from collections import deque

def solution(jobs):
    answer = 0
    q = deque(sorted(jobs))
    heap = []
    time = 0
    
    while True:
        if len(heap) == 0:
            if len(q) == 0:
                break
            else:
                front = q.popleft()
                
                heappush(heap, [front[1], front[0]])
                
        else:
            head = heappop(heap)
            request, working = head[1], head[0]
            
            time = max(time, head[1]) + working
            answer += (time - request)
            
            while len(q) > 0 and q[0][0] <= time:
                front = q.popleft()
                heappush(heap, [front[1], front[0]])
            
    answer //= len(jobs)
        
    return answer