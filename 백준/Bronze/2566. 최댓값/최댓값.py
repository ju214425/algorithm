arr = []
m, r, c = 0, 0, 0

for i in range(9):
    temp = list(map(int, input().split()))
    arr.append(temp)

for i in range(9):
    for j in range(9):
        if m < arr[i][j]:
            m = arr[i][j]
            r = i
            c = j

print(m)
print(r+1, c+1)