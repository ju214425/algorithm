import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())

d = {}
arr = []

for i in range(n):
    word = input().rstrip()
    
    if len(word) < m:
        continue
    
    if word not in d:
        d[word] = [0, len(word)] #cnt, len
        
    d[word][0] += 1
    
for key in d:
    arr.append([d[key][0], d[key][1], key])
    
arr = sorted(arr, key = lambda x : (-x[0], -x[1], x[2]))

for item in arr:
    print(item[2])