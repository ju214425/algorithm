def solution(a, b, c, d):
    answer = 0
    
    arr = [a, b, c, d]
    arr = sorted(arr)
    a, b, c, d = arr
    
    if a == b == c == d:
        answer = 1111 * a
    
    elif a == b == c != d:
        answer = (10 * a + d) ** 2
    
    elif a != b == c == d:
        answer = (10 * d + a) ** 2
    
    elif a == b and c == d:
        answer = (a + c) * abs(c - a)
    
    elif a == b and b != c and c != d:
        answer = c * d
        
    elif b == c and a != b and b != d:
        answer = a * d
        
    elif c == d and a != b and b != d:
        answer = a * b
    
    elif a != b != c != d:
        answer = a
    
    return answer