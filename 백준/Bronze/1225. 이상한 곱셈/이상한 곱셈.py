a, b = input().split()

answer = 0
temp = 0

for i in a:
    temp += int(i)

for j in b:
    answer += (temp * int(j))
  
print(answer)