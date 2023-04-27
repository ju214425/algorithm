def solution(genres, plays):
    answer = []
    
    d = {}
    l = []
    
    for idx, genre in enumerate(genres):
        if genre not in d:
            d[genre] = [0, []]
        
        d[genre][0] += plays[idx]
        d[genre][1].append([idx, plays[idx]])
    
    for key in d:
        d[key][1] = sorted(d[key][1], key = lambda x : (-x[1], x[0]))
    
        l.append(d[key])
    
    l = sorted(l, key = lambda x : -x[0])
    
    for idx, data in l:
        for idx, value in enumerate(data):
            if idx < 2:
                answer.append(value[0])
            
    return answer