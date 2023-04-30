def union_parent(arr, x, y):
    x = find_parent(arr, x)
    y = find_parent(arr, y)
    
    if x < y:
        arr[x] = y
    else:
        arr[y] = x
        
def find_parent(arr, x):
    if arr[x] == x:
        return arr[x]
    else:
        return find_parent(arr, arr[x])

def solution(n, computers):
    answer = n
    
    arr = [i for i in range(len(computers))]
    
    for i in range(len(computers)):
        for j in range(i+1, len(computers[i])):
            if computers[i][j] == 1:
                if find_parent(arr, i) != find_parent(arr, j):
                    union_parent(arr, i, j)
                    answer -= 1
    
    return answer