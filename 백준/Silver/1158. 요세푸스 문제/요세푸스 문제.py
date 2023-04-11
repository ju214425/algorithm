from collections import deque

n, k = map(int, input().split())

arr = [i for i in range(1, n+1)]

answer = []

idx = 0

q = deque(arr)

while q:
    front = q.popleft()

    if (idx+1) % k == 0:
        answer.append(front)
    else:
        q.append(front)

    idx += 1

print('<' + str(answer)[1:-1] + '>')