from itertools import permutations as p

n, m = map(int, input().split())

arr = sorted(list(map(int, input().split())))

s = set()

for item in p(arr, m):
    s.add(item)
    
answer = sorted(list(s))

for item in answer:
    print(' '.join(map(str, item)))