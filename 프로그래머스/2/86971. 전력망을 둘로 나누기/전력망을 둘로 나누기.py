import copy

def search(g, v, node):
    if len(node) != 0:
        for next_node in node:
            if v[next_node] == 0:
                v[next_node] = 1
                search(g, v, list(g[next_node]))

def check(g, wire):
    s = len(g) - 1
    g[wire[0]].remove(wire[1])
    g[wire[1]].remove(wire[0])
    
    v = [0 for _ in range(len(g))]
    v[wire[0]] = 1
    search(g, v, list(g[wire[0]]))
    return abs(2 * sum(v) - s)
    

def solution(n, wires):
    answer = 987654321
    
    graph = [set() for _ in range(n+1)]
    
    for wire in wires:
        graph[wire[0]].add(wire[1])
        graph[wire[1]].add(wire[0])
        
    for i in range(len(wires)):
        g = copy.deepcopy(graph)
        answer = min(answer, check(g, wires[i]))
        
    return answer