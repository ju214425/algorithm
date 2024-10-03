import math 

def solution(n, stations, w):
    answer = 0
    
    r = 2*w+1
    now = 1
    for s in stations:
        length = s - w - now
        if length > 0:
            answer += math.ceil(length / r)
        now = s + w + 1

    if now <= n:
        answer += math.ceil((n-now+1) / r)
        
    return answer