n, m = map(int, input().split())

arr = [i for i in range(n+1)]

for _ in range(m):
    i, j, k = map(int, input().split())

    arr[i:j+1] = arr[k:j+1] + arr[i:k]

for i in range(1, len(arr)):
    print(arr[i], end = ' ')