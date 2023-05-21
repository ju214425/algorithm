n = int(input())

def func(x, y, val):
    global ans1, ans2
    if val == 0:
        return
    
    s = 0
    for i in arr[x:x+val]:
        for j in i[y:y+val]:
            s += j
    
    if s == val * val:
        ans2 += 1
    elif s == 0:
        ans1 += 1
    else:
        func(x, y, val//2)
        func(x + val//2, y, val//2)
        func(x, y + val//2, val//2)
        func(x + val//2, y + val//2, val//2)

ans1 = 0
ans2 = 0
arr = []

for i in range(n):
    arr.append(list(map(int, input().split())))

func(0, 0, n)

print(ans1)
print(ans2)