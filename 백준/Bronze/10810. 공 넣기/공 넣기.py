n, m = map(int, input().split())

arr = [0] * (n+1)

for _ in range(m):
    i, j, k = map(int, input().split())

    for t in range(i, j+1):
        arr[t] = k

for i in range(1, len(arr)):
    print(arr[i], end = ' ')