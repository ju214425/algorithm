def solution(n, s):
    answer = []
    
    minimum = int(s / n)
    diff = s - (n * minimum)
    
    if minimum == 0:
        answer.append(-1)
    
    else:
        answer = [minimum] * n
        
        for i in range(diff):
            answer[i] += 1
        
    answer = sorted(answer)
    
    return answer
