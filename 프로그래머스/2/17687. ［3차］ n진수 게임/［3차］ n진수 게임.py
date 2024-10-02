def tenToN(num, n):
    ret = ''
    number = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'][:n]
    
    while num != 0:
        ret += number[num % n]
        num //= n
        
    return ret[::-1]

def solution(n, t, m, p):
    answer = ''
    value = '0'
    
    for i in range(t*m+1):
        value += tenToN(i, n)
    
    for i in range(p-1, t * m, m):
        answer += value[i]
        if len(answer) == t:
            break
    
    return answer