temp = {}
tree = {}

def propagate(seller, money):
    if seller == "-":
        return

    else :
        if (money >= 10):
            temp[seller] += (money - (money // 10))
            
        else :
            temp[seller] += money
            return
        seller = tree[seller]
        
        propagate(seller, money // 10)
        

def solution(enroll, referral, seller, amount):
    answer = []

    for i in range(len(enroll)):
        tree[enroll[i]] = referral[i]
        temp[enroll[i]] = 0
        
    for i in range(len(seller)):
        propagate(seller[i], 100*amount[i])                
    
    for t in temp.values():
        answer.append(t)
        
    return answer