def solution(sequence, k):
    answer = []
    
        
    subSum = 0
    end = 0

    
    arr = []
    
    for start in range(len(sequence)):
        while subSum < k and end < len(sequence):
            subSum += sequence[end]
            end += 1
        
        if subSum == k:
            arr.append([end-start-1, start, end])
        
        subSum -= sequence[start]
    
    arr.sort()
    
    answer = [arr[0][1], arr[0][2]-1]
    
    return answer