def isCorrect(p):
    check = 0
    for item in p:
        if item == '(':
            check += 1
        else:
            check -= 1
        if check < 0:
            return False
    
    if check == 0:
        return True
    else:
        return False

def recursiveFunction(w):
    if len(w) == 0:
        return ''
    
    left = 0
    right = 0
    
    for item in w:
        if item == '(':
            left += 1
        else:
            right += 1
        if left == right:
            break
            
    u = w[:left+right]
    v = w[left+right:]
    
    if isCorrect(u):
        return u + recursiveFunction(v)
    else:
        return '('+ recursiveFunction(v) + ')' + changeDirection(u[1:-1])

def changeDirection(u):
    ret = ''
    for item in u:
        if item == '(':
            ret += ')'
        else:
            ret += '('
    
    return ret
    
def solution(p):
    answer = ''
    
    answer = recursiveFunction(p)
    
    return answer