n = int(input())

# number = 4_000_001
number = n+1

arr = [i for i in range(number)]
answer = 0
s = set()

arr[1] = 0

for i in range(2, number):
    if arr[i] == 0:
        continue
    
    for j in range(i*2, number, i):
        arr[j] = 0

for i in range(number):
    if arr[i] != 0:
        s.add(i)
        
s = sorted(list(s))

p2 = 0
subtotal = 0

for p1 in range(len(s)):
    while subtotal < n and p2 < len(s):
        subtotal += s[p2]
        p2 += 1
    
    if subtotal == n:
        answer += 1
        
    subtotal -= s[p1]
        
print(answer)