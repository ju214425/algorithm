import sys
input = sys.stdin.readline

n = int(input())

d = {}

for _ in range(n):
    a, b = input().split()
    if b == 'enter':
        d[a] = 1
    else:
        d.pop(a)

arr = []

for item in d:
    arr.append(item)

arr.sort(reverse = True)

for item in arr:
    print(item)