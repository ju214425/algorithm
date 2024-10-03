import heapq as hq

n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

study = 24 * n
pq = []

answer = 0

for i in range(m):
    hq.heappush(pq, (-b[i], a[i]))

while pq and study > 0:
    fb, fa = hq.heappop(pq)
    div = (100 - fa) // (-fb)
    if study > div :
        temp = fa + div * (-fb)
        if temp == 100:
            answer += 100
        else:
            hq.heappush(pq, (-(100-temp), temp))
        study -= div
    else:
        answer += ( fa + study * (-fb) )
        study = 0
        
for fb, fa in pq:
    answer += fa

print(answer)