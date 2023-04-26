from itertools import combinations as C

def solution(relation):
    answer = 0
    column = len(relation[0])
    key = []
    
    for i in range(1, column+1):
        for k in list(C(range(column), i)):
            key.append(k)

    answerSet = set()
    for k in key:
        #유일성 체크
        s = set()
        answerFlag = False
        for r in relation:
            temp = []
            for idx in k:
                temp.append(r[idx])
            temp = tuple(temp)
            if temp not in s:
                s.add(temp)
            else:
                break
        else:
            #최소성 체크
            for i in range(1, len(k)+1):
                if answerFlag:
                    break
                for j in list(C(k, i)):
                    if j in answerSet:
                        answerFlag = True
                        break
            else:
                answerSet.add(k)
                    
    answer = len(answerSet)
            
    return answer