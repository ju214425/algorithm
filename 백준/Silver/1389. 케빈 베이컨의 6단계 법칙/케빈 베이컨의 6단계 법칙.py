n, m = map(int, input().split())

inf = 987654321
graph = [[inf for _ in range(n+1)] for _ in range(n+1)]
dist = inf
answer = 1

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1
    
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if graph[i][k] + graph[k][j] < graph[i][j]:
                graph[i][j] = graph[i][k] + graph[k][j]
          
for i in range(1, n+1):
    temp = 0
    for j in range(1, n+1):
        if graph[i][j] != inf:
            temp += graph[i][j]
    
    if temp < dist:
        dist = temp
        answer = i

print(answer)