from math import ceil

def solution(fees, records):
    answer = []
    
    l = []
    d = {}
    
    for record in records:
        [time, number, inout] = record.split()
        
        l.append([time.split(':')[0], time.split(':')[1], number, inout])
        
        if number not in d:
            d[number] = []
        
        d[number].append([int(time.split(':')[0]), int(time.split(':')[1]), inout])
        
    for key in d:
        incar = []
        outcar = []
        for index, item in enumerate(d[key]):
            if item[2] == 'IN':
                incar.append(item)
            else:
                outcar.append(item)
            
        if len(incar) != len(outcar):
            outcar.append([23, 59, 'OUT'])
        
        time = 0
        pay = fees[1]
        for index, item in enumerate(incar):
            time +=  ((outcar[index][0] - incar[index][0]) * 60 + (outcar[index][1] - incar[index][1]))
    
        if time // fees[0] > 0:
            pay += ceil((time - fees[0])/fees[2]) * fees[3]
        
        d[key] = pay
        
        

    
    for i in sorted(d.items()) :
         answer.append(i[1])
    
    return answer