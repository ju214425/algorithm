n, k = map(int, input().split())

arr = list(map(int, input().split()))

arr = sorted(arr, key = lambda x : -x)

print(arr[k-1])