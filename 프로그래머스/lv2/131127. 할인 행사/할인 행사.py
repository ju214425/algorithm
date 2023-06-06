from collections import Counter

def solution(want, number, discount):
    answer = 0
    
    d = {}
    
    for w, n in zip(want, number):
        d[w] = n
        
    for i in range(len(discount)-9):
        if d == Counter(discount[i:i+10]):
            answer += 1
    
    return answer