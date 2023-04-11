def solution(data, col, row_begin, row_end):
    answer = 0
    
    data = sorted(data, key = lambda x : (x[col-1], -x[0]))
    
    for i in range(row_begin-1, row_end):
        s_i = 0
        for c in data[i]:
            s_i += (c % (i+1))
        
        answer ^= s_i
        
    
    return answer