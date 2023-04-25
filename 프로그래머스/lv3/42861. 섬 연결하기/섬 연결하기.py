def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
    
def find(parent, a):
    if parent[a] != a:
        parent[a] = find(parent, parent[a])
    return parent[a]


def solution(n, costs):
    answer = 0
    
    costs = sorted(costs, key = lambda x : x[2])
    
    parent = [i for i in range(n)]
    
    
    for u, v, w in costs:
        if find(parent, u) != find(parent, v):
            union(parent, u, v)
            answer += w
    
    return answer