import math

n = int(input())
arr = list(map(int, input().split()))
t, p  = map(int, input().split())

T = P1 = P2 = 0

for i in range(6):
    T += math.ceil(arr[i] / t)
P1 = math.ceil(n // p)
P2 = n % p

print(T)
print(P1, P2)