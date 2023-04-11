n = int(input())

arr = []

answer = n

for i in range(n):
    arr.append(input()) 
    
for word in arr:
    d = {}

    for i, w in enumerate(word):
        if w not in d:
            d[w] = i
        else:
            if d[w] == i-1:
                d[w] = i
            else:
                answer -= 1
                break
        
        
print(answer)