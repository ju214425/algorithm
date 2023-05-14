from collections import deque

n, m = map(int, input().split())

answer = []

indegree = [0] * (n+1)
arr = [[] for _ in range(n+1)]

q = deque()

for _ in range(m):
    a, b = (map(int, input().split()))
    arr[a].append(b)
    indegree[b] += 1
    
for i in range(1, n+1):
    if indegree[i] == 0:
        q.append(i)
        
for i in range(1, n+1):
    f = q.popleft()
    answer.append(str(f))
    
    for nextNode in arr[f]:
        indegree[nextNode] -= 1
        if indegree[nextNode] == 0:
            q.append(nextNode)

answer = ' '.join(answer)

print(answer)
            