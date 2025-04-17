def check(s1, s2):
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            return False
    
    return True

def solution(phone_book):
    answer = True
    
    phone_book = sorted(phone_book)
    
    for i in range(len(phone_book)-1):
        if check(phone_book[i], phone_book[i+1]):
            answer = False
            return answer
                
    return answer