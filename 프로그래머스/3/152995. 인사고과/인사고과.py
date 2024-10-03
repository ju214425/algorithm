def solution(scores):
    answer = -1
    
    cs = list()
    arr = list()
    d = dict()
    
    for idx, score in enumerate(scores):
        cs.append( (score[0], score[1], idx) )
    
    cs.sort(key = lambda x :(-x[0], -x[1]))
    
    prevX = cs[0][0]
    prevY = cs[0][1]
    currX = cs[0][0]
    currY = cs[0][1]
    arr.append(cs[0])
    
    for i in range(1, len(cs)):
        if cs[i-1][0] != cs[i][0]:
            prevX = currX
            prevY = max(prevY, currY)
            currX = cs[i][0]
            currY = max(currY, cs[i][1])
        
        if cs[i][0] < prevX and cs[i][1] < prevY:
            pass
        else:
            arr.append(cs[i])
        
    arr.sort(key = lambda x: (-(x[0] + x[1]), x[2]))
    
    for idx, val in enumerate(arr):
        if val[2] == 0:
            answer = idx + 1
            
    return answer