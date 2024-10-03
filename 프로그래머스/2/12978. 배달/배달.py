def solution(N, road, K):
    answer = 0
    inf = 987654321
    dist = [[ inf for _ in range(N+1) ] for _ in range(N+1)]

    for i in range(1, N+1):
        dist[i][i] = 0
    
    for r in road:        
        if dist[r[0]][r[1]] > r[2]:
            dist[r[0]][r[1]] = r[2]
            dist[r[1]][r[0]] = r[2]
                
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
            
    for i in dist[1]:
        if i <= K:
            answer += 1
        
    return answer