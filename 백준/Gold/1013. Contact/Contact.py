import re

p = re.compile('(100+1+|01)+')

t = int(input())

for i in range(t):
    a = input()
    
    if p.fullmatch(a):
        print("YES")
    else:
        print("NO")