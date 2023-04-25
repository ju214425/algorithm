n = int(input())

s = set()
s.add('ChongChong')

for _ in range(n):
    a, b = input().split()
    if a in s:
        s.add(b)
    
    elif b in s:
        s.add(a)
        
print(len(s))