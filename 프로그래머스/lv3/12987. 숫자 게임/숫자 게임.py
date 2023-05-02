def solution(A, B):
    answer = 0
    
    A = sorted(A)
    B = sorted(B)
    p1 = 0
    p2 = 0
    
    while p2 != len(B):
        if A[p1] < B[p2]:
            p1 += 1
            p2 += 1
            answer += 1
        else:
            p2 += 1
    
    return answer
