def solution(people, limit):
    answer = 0
    
    people = sorted(people, key = lambda x: -x)
    
    cur = 0
    
    p1 = 0
    p2 = len(people)-1
    
    while p1 <= p2:
        cur = people[p1]
        while(True):
            if cur + people[p2] > limit:
                break
            else:
                cur += people[p2]
                p2 -= 1
            
        p1 += 1
        answer += 1
    
    return answer