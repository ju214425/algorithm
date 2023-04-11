from collections import deque

n = int(input())

answer = 0
arr = [0] * 1000001

q = deque()
q.append(n)

while q:
    front = q.popleft()
    if front == 1:
        answer = arr[1]
        break
  
    if front % 2 == 0 and arr[front//2] == 0:
        q.append(front // 2)
        arr[front // 2] = arr[front] + 1

    if front % 3 == 0 and arr[front//3] == 0:
        q.append(front // 3)
        arr[front // 3] = arr[front] + 1

    if front > 1 and arr[front - 1] == 0:
        q.append(front - 1)
        arr[front - 1] = arr[front] + 1

print(answer)