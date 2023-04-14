import math

def solution(r1, r2):
    answer = 0
    
    for i in range(1, r2+1):
        answer += (math.floor(math.sqrt(pow(r2, 2) - pow(i, 2))) \
                   - math.ceil(math.sqrt(max(pow(r1, 2) - pow(i, 2), 0))) \
                   + 1) * 4
        
    return answer