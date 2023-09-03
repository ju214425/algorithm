from itertools import combinations as c
from collections import Counter as C

def diff(str1, str2):
    cnt = 0
    for i in range(4):
        if str1[i] != str2[i]:
            cnt += 1

    return cnt

t = int(input())

for _ in range(t):
    n = int(input())
    l = input().split()
    count = dict(C(l))
    arr = []
    answer = 987654321
    
    for k in count:
        if count[k] >= 3:
            answer = 0
            break
        else:
            for i in range(count[k]):
                arr.append(k)
    
    for item in c(arr, 3):
        temp = 0
        temp += diff(item[0], item[1])
        temp += diff(item[1], item[2])
        temp += diff(item[2], item[0])
        
        answer = min(answer, temp)

    print(answer)