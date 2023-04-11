answer = 0
now = 0
while True:
    try:
        a, b = map(int, input().split())
    
        now -= a
        now += b
        answer = max(answer, now)
    
    except:
        break
print(answer)