def solution(n, left, right):
    answer = []
    
    start = [left//n, left%n]
    end = [right//n, right%n]
    
    x, y = start[0], start[1]
        
    while True:
        answer.append(max(x, y)+1)
        
        if y + 1 == n:
            y = 0
            x += 1
        else:
            y += 1
        
        if x == end[0] and y == end[1]:
            break
    
    answer.append(max(end[0], end[1])+1)
    
    return answer