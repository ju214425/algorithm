n, m = map(int, input().split())

arr = [i for i in range(n+1)]

for _ in range(m):
    i, j = map(int, input().split())

    arr[i:j+1] = arr[j:i-1:-1]

for i in range(1, len(arr)):
    print(arr[i], end = ' ')