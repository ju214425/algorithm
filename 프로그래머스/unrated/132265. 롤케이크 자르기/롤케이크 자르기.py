from collections import Counter as C

def solution(topping):
    answer = 0
    
    d1 = {}
    d2 = {}
    
    for t in topping:
        if t not in d1:
            d1[t] = 0
        d1[t] += 1
    
    for t in topping:
        d1[t] -= 1
        if d1[t] == 0:
            d1.pop(t)
        
        if t not in d2:
            d2[t] = 0
        
        d2[t] += 1
        
        if len(d1) == len(d2):
            answer += 1
    
    return answer