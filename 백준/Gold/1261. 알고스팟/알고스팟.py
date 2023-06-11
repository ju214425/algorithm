from heapq import *

m, n = map(int, input().split())
INF = 987654321

graph = []
d = [[INF] * m for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1 ,0]

for i in range(n):
	string = input()
	temp = []
	for j in range(m):
		temp.append(int(string[j]))
	graph.append(temp)

def dijkstra(x, y):
    d[x][y] = 0
    heap = []
    heappush(heap, [x, y, 0])
    
    while len(heap) != 0:
        cx, cy, distance = heappop(heap)
        
        if d[cx][cy] < distance:
            continue
        
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m:
                nextDistance = distance + graph[nx][ny]
                
                if nextDistance < d[nx][ny]:
                    d[nx][ny] = nextDistance
                    heappush(heap, [nx, ny, nextDistance])

dijkstra(0, 0)

print(d[n-1][m-1])