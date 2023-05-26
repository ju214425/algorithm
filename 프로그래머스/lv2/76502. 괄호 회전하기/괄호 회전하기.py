def solution(string):
    answer = 0
    
    for i in range(len(string)):
        s = string[i:] + string[:i]
        
        arr = [s[0]]

        for idx, c in enumerate(s[1:]):
            if len(arr) != 0:
                if arr[-1] == '{' and c == '}':
                    arr.pop()
                    continue
                elif arr[-1] == '(' and c == ')':
                    arr.pop()   
                    continue
                    
                elif arr[-1] == '[' and c == ']':
                    arr.pop()
                    continue
                
            arr.append(c)
        
        if len(arr) == 0:
            answer += 1
    
    return answer