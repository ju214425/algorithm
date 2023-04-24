from collections import deque

def topology_sort():
    result = []
    q = deque()
    
    for i in range(1, n+1):
        if indegree[i] == 0:
            q.append(i)
    
    while q:
        front = q.popleft()
        result.append(front)
        
        for i in graph[front]:
            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)
    
    return result

t = int(input())
 
for _ in range(t):
    n, k = map(int, input().split())
    d = [0] + list(map(int, input().split()))
    
    indegree = [0] * (n+1)
    graph = [[] for _ in range(n+1)]
    cost = [0] * (n+1)
    
    for _ in range(k):
        x, y = map(int, input().split())
        graph[x].append(y)
        indegree[y] += 1
    
    for i in range(n+1):
        if indegree[i] == 0:
            cost[i] = d[i]
    
    w = int(input())
    
    arr = topology_sort()
    
    for i in range(len(arr)):
        for n in graph[arr[i]]:
            cost[n] = max(cost[n], cost[arr[i]] + d[n])
    
    print(cost[w])