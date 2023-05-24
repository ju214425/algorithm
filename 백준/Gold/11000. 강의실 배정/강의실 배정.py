import sys

n = int(input())

S = set()
d = dict()
a = list()
answer = 0

for i in range(n):
    s, t = map(int, sys.stdin.readline().strip().split())
    a.append([s, t])
    
    S.add(s)
    S.add(t)
    
S = sorted(list(S))
arr = [0] * len(S)

a = sorted(a)

for idx, val in enumerate(S):
    d[val] = idx
    
for s, t in a:
    arr[d[s]] += 1
    arr[d[t]] -= 1

for i in range(1, len(arr)):
    arr[i] += arr[i-1]
    answer = max(answer, arr[i])
    
print(answer)