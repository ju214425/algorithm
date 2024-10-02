def solution(land):
    answer = 0
    
    queue = []
    
    v = dict()
    oil = dict()
    idx = 0
    
    dx = (1, 0, -1, 0)
    dy = (0, 1, 0, -1)
    
    for j in range(len(land[0])):
        for i in range(len(land)):
            if land[i][j] == 1 and (i, j) not in v:
                v[(i, j)] = idx
                queue.append((i, j))
                o = 1
                while queue:
                    front = queue.pop(0)
                    
                    for k in range(4):
                        nx = front[0] + dx[k]
                        ny = front[1] + dy[k]
                        if 0 <= nx < len(land) and 0 <= ny < len(land[0]) and land[nx][ny] == 1 and (nx, ny) not in v:
                            queue.append((nx, ny))
                            v[(nx, ny)] = idx
                            o += 1
                            
                
                oil[idx] = o
                idx += 1
                
#     for key in v:
#         print(key, v[key], oil[v[key]])
        
    for j in range(len(land[0])):
        local_visit = dict()
        local_answer = 0
        for i in range(len(land)):
            if land[i][j] == 1 and v[(i, j)] not in local_visit:
                local_visit[v[(i, j)]] = 1
                local_answer += oil[v[(i, j)]]

        answer = max(answer, local_answer)
                
    
    return answer