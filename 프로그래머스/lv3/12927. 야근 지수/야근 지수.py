from heapq import *

def solution(n, works):
    answer = 0
    
    h = []
    
    if sum(works) < n:
        return 0
    
    for item in works:
        h.append(-item)
        
    heapify(h)
    
    while n != 0:
        top = heappop(h)
        top += 1
        heappush(h,top)
        n -= 1
        
    for item in list(h):
        answer += pow(item, 2)
    
    return answer