def solution(s):
    answer = []
    
    splited = s.split('}')
    
    d = {}
    
    for data in splited:
        data = data.replace('{', '')
        for num in data.split(','):
            if len(num) != 0:
                if int(num) not in d:
                    d[int(num)] = 0
                d[int(num)] += 1
    
    temp = []
    for key in d:
        temp.append([key, d[key]])
        
    temp = sorted(temp, key = lambda x : -x[1])
    
    for item in temp:
        answer.append(item[0])
        
        
    return answer