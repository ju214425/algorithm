import sys
input = sys.stdin.readline

n = int(input().rstrip())

s = set()

answer = 0

for _ in range(n):
    data = input().rstrip()
    if data == 'ENTER':
        s = set()
    else:
        if data not in s:
            s.add(data)
            answer += 1

print(answer)