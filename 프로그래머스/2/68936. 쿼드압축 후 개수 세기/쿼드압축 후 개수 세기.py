def sum_(arr, sx, sy, l):
    ret = 0
    for i in range(sx, sx+l):
        for j in range(sy, sy+l):
            ret += arr[i][j]
            
    return ret

def recv(arr, sx, sy, l):
    ret = [0, 0]
    if sum_(arr, sx, sy, l) == 0:
        return [1, 0]
    elif sum_(arr, sx, sy, l) == l*l:
        return [0, 1]
    
    a1 = recv(arr, sx,        sy,        l//2)
    a2 = recv(arr, sx + l//2, sy,        l//2)
    a3 = recv(arr, sx,        sy + l//2, l//2)
    a4 = recv(arr, sx + l//2, sy + l//2, l//2)

    ret[0] = a1[0] + a2[0] + a3[0] + a4[0]
    ret[1] = a1[1] + a2[1] + a3[1] + a4[1]
    
    return ret

def solution(arr):
    answer = []
    
    answer = recv(arr, 0, 0, len(arr))
    
    return answer