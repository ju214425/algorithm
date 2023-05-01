def solution(m, n, startX, startY, balls):
    answer = []
    
    for b in balls:
        l = []
        x = b[0]
        y = b[1]
        if not (startX == x and y > startY):
            l.append([x, 2*n - y])
        if not (startX == x and startY > y):        
            l.append([x, -y])
        if not (startX > x and startY == y):     
            l.append([-x, y])   
        if not (startX < x and startY == y):    
            l.append([2*m - x, y])
        
        minimum = pow(l[0][0] - startX, 2) + pow(l[0][1] - startY, 2)
        
        for item in l:
            minimum = min(minimum, pow(item[0] - startX, 2) + pow(item[1] - startY, 2))
        
        answer.append(minimum)
        
    return answer