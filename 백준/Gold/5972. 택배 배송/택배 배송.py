import heapq

def dijkstra(n, graph):
    inf = 987654321
    
    dist = [inf] * (n+1)
    
    dist[1] = 0
    
    queue = [(0, 1)]
    
    while queue:
        curr_cost, curr_node = heapq.heappop(queue)
        
        if curr_cost > dist[curr_node]:
            continue
        
        for next_cost, next_node in graph[curr_node]:
            total_cost = curr_cost + next_cost
            
            if total_cost < dist[next_node]:
                dist[next_node] = total_cost
                heapq.heappush(queue, (total_cost, next_node))
    
    return dist
    
n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))
    
result = dijkstra(n, graph)

print(result[n])