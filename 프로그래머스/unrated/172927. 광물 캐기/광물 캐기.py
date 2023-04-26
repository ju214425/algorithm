def solution(picks, minerals):
    answer = 0
    
    mArr = [[0, 0, 0]]
    D, I, S = picks
    num = sum(picks)
    
    for mineral in minerals:
        if sum(mArr[len(mArr)-1]) == 5:
            mArr.append([0, 0, 0])
            
        if mineral == 'diamond':
            mArr[len(mArr)-1][0] += 1
        elif mineral == 'iron':
            mArr[len(mArr)-1][1] += 1
        else:
            mArr[len(mArr)-1][2] += 1
    
    mArr = mArr[:num]
    mArr = sorted(mArr, key = lambda x : (-x[0], -x[1], -x[2]))
    
    for m in mArr:
        if D != 0:
            D -= 1
            answer += (m[0] + m[1] + m[2])
        elif I != 0:
            I -= 1
            answer += (m[0] * 5 + m[1] + m[2])
        else:
            S -= 1
            answer += (m[0] * 25 + m[1] * 5 + m[2])
            
    return answer