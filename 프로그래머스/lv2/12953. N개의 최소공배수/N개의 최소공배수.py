from math import gcd

def solution(arr):
    answer = 1
    
    for i in range(len(arr)):
        answer = answer * arr[i] // gcd(answer, arr[i])
    
    return answer