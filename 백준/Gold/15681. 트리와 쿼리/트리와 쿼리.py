import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)

input = sys.stdin.readline
N, R, Q = map(int, input().split())

child = defaultdict(list)
connect = defaultdict(list)
parent_dict = defaultdict(int)
size = defaultdict(int)

for _ in range(N-1):
    u, v = map(int, input().split())
    connect[u].append(v)
    connect[v].append(u)
    
    
def makeTree(currentNode, parent):
    for node in connect[currentNode]:
        if node != parent:
            child[currentNode].append(node)
            parent_dict[node] = currentNode
            makeTree(node, currentNode)
            
def countSubtreeNodes(currentNode):
    size[currentNode] = 1
    for node in child[currentNode]:
        countSubtreeNodes(node)
        size[currentNode] += size[node]

makeTree(R, -1)
countSubtreeNodes(R)

for _ in range(Q):
    print(size[int(input())])