from itertools import permutations as p

def solution(numbers):
    answer = 0
    
    arr = []
    s = set()
    pr = set()
    
    for i in range(1, len(numbers)+1):
        arr.extend(p(numbers, i))
    
    for item in arr:
        s.add(int(''.join(item)))
    
    prime = [True] * (max(s)+1)
    prime[0] = False
    prime[1] = False
    
    for i in range(2, int(max(s) ** 0.5)+1):
        if prime[i] == False:
            continue
        for j in range(i*2, max(s)+1, i):
            prime[j] = False
            
    for idx, item in enumerate(prime):
        if item:
            pr.add(idx)
    
    answer = len(s & pr)
    
    return answer