from collections import deque

n, k = map(int, input().split())

q = deque() 
d = [987654321] * 100001
answer2 = 0

q.append(n)
d[n] = 0

while len(q) != 0:
    f = q.popleft()
    
    if f == k:
        answer2 += 1
    
    if d[f] > d[k]:
        break
    
    if 2 * f <= 100000:
        if d[2 * f] >= d[f] + 1:
            d[2 * f] = d[f] + 1
            q.append(2 * f) 
        
    if f + 1 <= 100000:
        if d[f + 1] >= d[f] + 1:
            d[f + 1] = d[f] + 1
            q.append(f + 1)
            
    if f - 1 >= 0:
        if d[f - 1] >= d[f] + 1:
            d[f - 1] = d[f] + 1
            q.append(f - 1)

if n == k:
    answer2 = 1

print(d[k])
print(answer2)