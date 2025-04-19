import math
from collections import defaultdict

def time_to_int(time):
    hh, mm = time.split(':')
    hh = int(hh) * 60
    mm = int(mm)
    
    return hh + mm
    
def solution(fees, records):
    answer = []
    temp = []
    d = defaultdict(int)
    cnt = defaultdict(int)
    
    for record in records:
        time, number, io = record.split()
        modified_time = time_to_int(time)
        
        if io == 'IN':
            d[number] -= modified_time
            cnt[number] += 1    
        else:
            d[number] += modified_time
            cnt[number] -= 1
        
    for key in d:
        if cnt[key] != 0:
            d[key] += 23*60+59
        
        money = fees[1] + fees[3] * math.ceil(max(d[key] - fees[0], 0) / fees[2])
        temp.append((key, money))
        
    temp.sort()
        
    for t in temp:
        answer.append(t[1])
        
    return answer