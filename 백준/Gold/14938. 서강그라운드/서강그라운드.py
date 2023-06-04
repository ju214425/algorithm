from heapq import *

n, m, r = map(int, input().split())

tarr = [0] + list(map(int, input().split()))

graph = [[] for _ in range(n+1)]
answer = 0
INF = 987654321

for i in range(r):
    a, b, l = map(int, input().split())
    graph[a].append([b, l])
    graph[b].append([a, l])

def dijkstra(start):
    d[start] = 0
    heap = []
    heapify(heap)
    heappush(heap, [start, 0])
    
    while len(heap) != 0:
        current, distance = heappop(heap)
        if d[current] < distance:
            continue
        for n, dist in graph[current]:
            nextDistance = distance + dist
            if nextDistance < d[n]:
                d[n] = nextDistance
                heappush(heap, [n, nextDistance])

for i in range(1, n+1):
    temp = 0
    d = [INF] * (n+1)
    dijkstra(i)
    
    for index, value in enumerate(d):
        if value <= m:
            temp += tarr[index]
    
    answer = max(answer, temp)

print(answer)