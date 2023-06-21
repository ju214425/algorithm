import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
m = int(input())

INF = 987654321
graph = [[] for _ in range(n+1)]
d = [INF] * (n+1)
path = [0] * (n+1)
p = []

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append([v, w])

s, e = map(int, input().split())

def dijkstra(start):
    d[start] = 0
    heap = []
    heappush(heap, [start, 0])
    
    while len(heap) != 0:
        current, distance = heappop(heap)
        
        if d[current] < distance:
            continue
        
        for next_, dist_ in graph[current]:
            nextDistance = distance + dist_
            
            if nextDistance < d[next_]:
                d[next_] = nextDistance
                heappush(heap, [next_, nextDistance])
                path[next_] = current
            
dijkstra(s)

p.append(str(e))
temp = path[e]

while temp != s:
    p.append(str(temp))
    temp = path[temp]
    
p.append(str(s))

p = p[::-1]

print(d[e])
print(len(p))
print(' '.join(p))