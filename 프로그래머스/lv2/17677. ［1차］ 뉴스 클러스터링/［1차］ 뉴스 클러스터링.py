def solution(str1, str2):
    answer = 65536
    
    set1 = set()
    set2 = set()
    
    d1 = {}
    d2 = {}
    
    for i in range(len(str1)-1):
        char = (str1[i] + str1[i+1]).upper()
        
        if ord('A') <= ord(char[0]) and ord(char[0]) <= ord('Z') and ord('A') <= ord(char[1]) and ord(char[1]) <= ord('Z'): 
            if char not in d1:
                d1[char] = 0
            d1[char] += 1
            set1.add(char)
    
    for i in range(len(str2)-1):
        char = (str2[i] + str2[i+1]).upper()
        
        if ord('A') <= ord(char[0]) and ord(char[0]) <= ord('Z') and ord('A') <= ord(char[1]) and ord(char[1]) <= ord('Z'): 
            if char not in d2:
                d2[char] = 0
            d2[char] += 1
            set2.add(char)

    
    interList = list(set1 & set2)
    unionList = list(set1 | set2)
    interValue = 0
    unionValue = 0
    
    for item in interList:
        interValue += min(d1[item], d2[item])
        
    for item in unionList:
        if item not in d1:
            unionValue += d2[item]
        elif item not in d2:
            unionValue += d1[item]
        else:
            unionValue += max(d1[item], d2[item])
    
    if unionValue != 0:
        answer = int((interValue / unionValue) * 65536)
    
    return answer