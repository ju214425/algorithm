def solution(k, ranges):
    answer = []
    
    arr = [k]
    s = [0]
    
    while k != 1:
        if k % 2 == 0:
            k //= 2
        else:
            k = k * 3 + 1
        arr.append(k)
        
    for i in range(1, len(arr)):
        s.append((arr[i-1] + arr[i])/2)
    
    for i in range(1, len(s)):
        s[i] = s[i] + s[i-1]
    
    
    for r in ranges:
        a, b = r[0], r[1]
        #s[i] = 0~i까지 적분값
        
        if not (0 <= a and a < len(s) and -len(s) < b and b <= 0):
            answer.append(-1)
            continue
            
        val = s[len(s)-1+b] - s[a]
        
        if val < 0:
            val = -1
        
        answer.append(val)
        
    return answer