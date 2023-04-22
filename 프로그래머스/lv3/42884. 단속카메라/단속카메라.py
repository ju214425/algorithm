def solution(routes):
    answer = 0
    
    routes = sorted(routes, key = lambda x : (x[1]))
    
    p = routes[0][1]
    answer += 1
    
    for idx, val in enumerate(routes):
        if val[0] > p:
            p = val[1]
            answer += 1
    
    return answer