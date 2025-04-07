def solution(n, w, num):
    answer = 0
    
    arr = [i for i in range(w)]
    arr = arr + arr[::-1]

    l = [[] for _ in range(w)]
    target = 0
    
    for i in range(n):
        if i+1 == num:
            target = arr[i%(2*w)]
        l[arr[i%(2*w)]].append(i+1)
    
    for idx, item in enumerate(l[target]):
        if item == num:
            answer = len(l[target]) - idx
    
    
    return answer