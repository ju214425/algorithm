from itertools import permutations as p

def solution(k, dungeons):
    answer = -1
    
    for seq in (list(p(range(len(dungeons))))):
        tired = k
        go = 0
        
        for s in seq:
            if tired >= dungeons[s][0]:
                tired -= dungeons[s][1]
                go += 1        
        
        answer = max(answer, go)
    
    return answer