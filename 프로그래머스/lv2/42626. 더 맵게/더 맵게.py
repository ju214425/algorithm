from heapq import *

def solution(scoville, K):
    answer = 0
    
    h = scoville
    heapify(h)
    
    if h[0] >= K:
        return answer
    
    while(h[0] < K):
        if len(h) == 1:
            return -1
        m1 = heappop(h)
        m2 = heappop(h)
        
        heappush(h, m1 + (m2 * 2))
        
        answer += 1
    
    return answer
