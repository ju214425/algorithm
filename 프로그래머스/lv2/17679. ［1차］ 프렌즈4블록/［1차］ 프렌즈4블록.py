def solution(m, n, board):
    answer = 0
    
    arr = []
    
    for i in range(len(board[0])):
        temp = []
        for j in range(len(board)-1, -1, -1):
            temp.append(board[j][i])
        arr.append(temp)
    
    idx = 0
    while True:
        idx += 1
        t = set()
        narr = [0] * len(arr)
        for i in range(len(arr)-1):
            for j in range(len(arr[0])-1):
                if arr[i][j] == arr[i+1][j] == arr[i][j+1] == arr[i+1][j+1] and arr[i][j] != '0':
                    t.add((i, j))
                    t.add((i+1, j))
                    t.add((i, j+1))
                    t.add((i+1, j+1))
        
        for item in t:
            narr[item[0]] += 1
            arr[item[0]][item[1]] = '1'
    
        for i in range(len(arr)):
            while arr[i].count('1') != 0:
                arr[i].pop(arr[i].index('1'))
                arr[i].append('0')
            
        if sum(narr) == 0:
            break

    for string in arr:
        answer += string.count('0')
            
    return answer