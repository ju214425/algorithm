def solution(numbers):
    answer = []
    
    arr = numbers[::-1]
    s = []

    for n in arr:
        while len(s) != 0 and n >= s[-1]:
            s.pop()
        
        if len(s) == 0:
            answer.append(-1)
        else:
            answer.append(s[-1])
            
        s.append(n)
        
    answer = answer[::-1]
    
    return answer