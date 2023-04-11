def solution(n):
    answer = ''
    
    a = n
    s = ''
    
    while a != 0:
        a -= 1
        s += str(a % 3)
        a //= 3
    
    s = s[::-1]
    
    answer = s.replace('2', '4').replace('1', '2').replace('0', '1')
    
    return answer