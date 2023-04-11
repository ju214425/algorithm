from heapq import *

def solution(operations):
    answer = [0, 0]
    
    maxheap = []
    minheap = []
    
    cnt = 0
    
    for data in operations:
        splited = data.split()
        oper, number = splited[0], splited[1]
        
        if oper == 'I':
            heappush(maxheap, -int(number))
            heappush(minheap, int(number))
            cnt += 1
            
        else:
            if cnt != 0:
                if number == '1':
                    heappop(maxheap)
                else:
                    heappop(minheap)
                cnt -= 1
                
                if cnt == 0:
                    maxheap = []
                    minheap = []
                    
    if cnt != 0:     
        answer = [-maxheap[0], minheap[0]]
    
    return answer