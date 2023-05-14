from math import *

n, m = map(int, input().split())

answer = -1

arr = [[0] * m for _ in range(n)]

for i in range(n):
    a = input()
    for j in range(m):
        arr[i][j] = a[j]
        if (int(arr[i][j]) ** 0.5) * (int(arr[i][j]) ** 0.5) == int(arr[i][j]):
            answer = max(answer, int(arr[i][j]))
    
for dx in range(-n+1, n):
    for dy in range(-m+1, m):
        if dx == 0 and dy == 0:
            continue
        for i in range(n):
            for j in range(m):
                x, y = i, j
                temp = ""
                idx = 0
                while 0 <= x < n and 0 <= y < m:
                    idx += 1
                    temp += arr[x][y]
                    x += dx
                    y += dy
                    data = int(temp)
                    
                    if int(data ** 0.5) * int(data ** 0.5) == data:
                        answer = max(answer, data)

print(answer)