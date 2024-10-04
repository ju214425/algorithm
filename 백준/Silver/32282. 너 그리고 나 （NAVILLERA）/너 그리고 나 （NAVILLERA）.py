import math
x, y, z = map(int, input().split())

answer = 0
dist = math.sqrt(x*x + y*y)
jump = z

if x == 0 and y == 0:
    answer = 0
    
elif dist == jump:
    answer = 1
else:
    if jump > dist:
        answer = 2
    else:
        answer = math.ceil( dist / jump )

print(answer)