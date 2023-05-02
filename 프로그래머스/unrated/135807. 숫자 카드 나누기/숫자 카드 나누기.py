from math import gcd as G

def solution(arrayA, arrayB):
    answer = 0
    
    ga = arrayA[0]
    gb = arrayB[0]
    
    for item in arrayA:
        ga = G(ga, item)

    for item in arrayB:
        gb = G(gb, item)
        
    if gb != 1:
        for item in arrayA:
            if item % gb == 0:
                break
        else:
            answer = max(answer, gb)
    
    if ga != 1:
        for item in arrayB:
            if item % ga == 0:
                break
        else:
            answer = max(answer, ga)
    
    return answer