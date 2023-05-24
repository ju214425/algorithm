import sys

from heapq import *

INF = 987654321

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
answer = [0] * (n+1)
distance = [INF] * (n+1)
s = set()

for i in range(m):
    a, b, c = map(int, sys.stdin.readline().strip().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

def dijkstra(start):
    h = []
    heappush(h, [start, 0])
    
    while len(h) != 0:
        c = heappop(h)
        cur = c[0]
        dist = c[1]
        
        if(distance[cur] < dist):
            continue
        
        for item in graph[cur]:
            n = item[0]
            ndist = dist + item[1]
            
            if ndist < distance[n]:
                distance[n] = ndist
                heappush(h, [n, ndist])
                answer[n] = cur
                
dijkstra(1)

print(n-1)
for i in range(1, n+1):
    if i < answer[i]:
        s.add((answer[i], i))
    else:
        s.add((i, answer[i]))

for item in s:
    print(item[0], item[1])