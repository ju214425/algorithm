from itertools import permutations as p

def solution(expression):
    answer = 0
    
    opers = list()
    
    if expression.find('+') != -1:
        opers.append('+')
    if expression.find('-') != -1:
        opers.append('-')
    if expression.find('*') != -1:
        opers.append('*')
    
    permu = p(opers, len(opers))
    
    e = expression
    e = e.replace('-', ' - ').replace('*', ' * ').replace('+', ' + ')
    number = e.split()
    
    for per in permu:
        temp_number = number.copy()
        for pe in per:
            while pe in temp_number:
                idx = temp_number.index(pe)
                value = 0
                if pe == '+':
                    value = int(temp_number[idx-1]) + int(temp_number[idx+1])
                elif pe == '*':
                    value = int(temp_number[idx-1]) * int(temp_number[idx+1])
                elif pe == '-':
                    value = int(temp_number[idx-1]) - int(temp_number[idx+1])
                
                temp_number[idx-1] = value
                del(temp_number[idx+1])
                del(temp_number[idx])
            
        answer = max(answer, abs(temp_number[0]))
    return answer