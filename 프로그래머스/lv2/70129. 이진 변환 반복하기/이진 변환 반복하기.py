def solution(s):
    answer = [0, 0]
    
    while(s != '1'):
        t = s.replace('0', '')
        answer[1] += (len(s) - len(t))
        s = bin(len(t))[2:]
        answer[0] += 1
        
    return answer