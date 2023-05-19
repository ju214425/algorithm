r, c = map(int, input().split())

arr = []
answer = ""
minVal = 10000
mx, my = 0, 0

cx, cy = 0, 0

def move(c, length):
    global answer
    answer += c * length

for i in range(r):
    temp = list(map(int, input().split()))
    
    for j in range(c):
        if (i + j) % 2 == 1:
            if minVal > temp[j]:
                minVal = temp[j]
                mx = i
                my = j
                
    arr.append(temp)
    
if r % 2 == 1:
    move("R", c-1)
    for i in range(0, r-1, 2):
        move("D", 1)
        move("L", c-1)
        move("D", 1)
        move("R", c-1)
    
elif c % 2 == 1:
    move("D", r-1)
    for i in range(0, c-1, 2):
        move("R", 1)
        move("U", r-1)
        move("R", 1)
        move("D", r-1)
        
else:
    while cx != mx and cx != mx-1:
        cx += 2
        move("R", c-1)
        move("D", 1)
        move("L", c-1)
        move("D", 1)
        
    while cy != my and cy != my-1:
        cy += 2
        move("D", 1)
        move("R", 1)
        move("U", 1)
        move("R", 1)
        
    if mx % 2 == 0:
        move("D", 1)
        move("R", 1)
    else:
        move("R", 1)
        move("D", 1)

    cx += 2
    cy += 2

    if cy != c:
        move("R", 1)
    else:
        if cx != r:
            move("D", 1)
    
    while cy != c:
        cy += 2
        move("U", 1)
        move("R", 1)
        move("D", 1)
        if cy != c:
            move("R", 1)
        else:
            if cx != r:
                move("D", 1)
            break
        
    while cx != r:
        cx += 2
        move("L", c-1)
        move("D", 1)
        move("R", c-1)
        if cx != r:
            move("D", 1)
        else:
            break

print(answer)