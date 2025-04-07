def solution(bandage, health, attacks):
    answer = 0
    
    continuous = 0
    
    max_health = health
    cur_health = health
    attacks_dict = {}
    
    for attack in attacks:
        attacks_dict[attack[0]] = attack[1]
    
    for i in range(1, attacks[-1][0]+1):
        if i in attacks_dict:
            continuous = 0
            cur_health -= attacks_dict[i]
            
            if cur_health <= 0:
                return -1
            
        else:
            continuous += 1
            cur_health += bandage[1]
            if continuous == bandage[0]:
                continuous = 0
                cur_health += bandage[2]
        
        cur_health = min(cur_health, max_health)
    return cur_health