def solution(line):
    answer = []
    
    s = set()
    
    minvx = 100000000000000000
    minvy = 100000000000000000
    maxvx = 0
    maxvy = 0
    
    for i in range(len(line)):
        a = line[i][0]
        b = line[i][1]
        e = line[i][2]
        for j in range(i+1, len(line)):
            c = line[j][0]
            d = line[j][1]
            f = line[j][2]
            
            if a*d - b*c == 0:
                continue
            
            x = (b*f - e*d) / (a*d - b*c)
            x_= (b*f - e*d) // (a*d - b*c)
            y = (e*c - a*f) / (a*d - b*c)
            y_= (e*c - a*f) // (a*d - b*c)
            
            if x == x_ and y == y_:
                s.add((x_, y_))
                minvx = min(minvx, x_)
                minvy = min(minvy, y_)
                
    arr = list(s)
    arr_ = []
    
    for i in range(len(arr)):
        arr_.append([arr[i][0] - minvx, arr[i][1] - minvy])
        maxvx = max(maxvx, arr[i][0] - minvx)
        maxvy = max(maxvy, arr[i][1] - minvy)
    
    for i in range(maxvy+1):
        temp = ''
        for j in range(maxvx+1):
            if [j, maxvy - i] in arr_:
                temp += '*'
            else:
                temp += '.'
                
        answer.append(temp)
    
    return answer