def solution(targets):
    answer = 1
    
    targets = sorted(targets, key = lambda x : (x[1], x[0]))

    pointer = targets[0][1] - 0.1
    
    for target in targets:
        if target[0] > pointer:
            pointer = target[1] - 0.1
            answer += 1
    
    return answer