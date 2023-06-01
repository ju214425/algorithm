def solution(k, tangerine):
    answer = 0
    
    d = {}
    arr = []
    
    for t in tangerine:
        if t not in d:
            d[t] = 0
        d[t] += 1
    
    for key in d:
        arr.append(d[key])
        
    arr.sort(reverse = True)
    
    temp = 0
    for item in arr:
        temp += item
        answer += 1
        if temp >= k:
            break
    
    return answer