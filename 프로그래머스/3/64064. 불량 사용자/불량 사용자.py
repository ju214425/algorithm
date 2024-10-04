from itertools import permutations as p

def match(s1, s2):
    for i in range(len(s2)):
        if len(s1[i]) != len(s2[i]):
            return False

        for j in range(len(s1[i])):
            if s1[i][j] != s2[i][j] and s2[i][j] != '*':
                return False
        
    return True
    
    
def solution(user_id, banned_id):
    s = list()
    perm = list(p(user_id, len(banned_id)))
    
    for user in perm:
        if match(user, banned_id):
            user = set(user)
            if user not in s:
                s.append(set(user))   
                
    return len(s)