def solution(tickets):
    from collections import defaultdict
    
    # 그래프를 딕셔너리 형태로 생성
    graph = defaultdict(list)
    for a, b in tickets:
        graph[a].append(b)
    
    # 각 출발지에서의 도착지를 알파벳 순으로 정렬
    for key in graph:
        graph[key].sort(reverse=True)
    
    route = []
    
    # DFS 탐색
    def dfs(airport):
        while graph[airport]:
            next_airport = graph[airport].pop()
            dfs(next_airport)
        route.append(airport)
    
    dfs('ICN')  # ICN 공항에서 출발
    return route[::-1]  # 역순으로 경로를 반환