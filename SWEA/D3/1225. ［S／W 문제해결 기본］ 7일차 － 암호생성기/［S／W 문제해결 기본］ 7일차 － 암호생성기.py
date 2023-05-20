from collections import deque

for test_cases in range(1, 11):
    answer = 0

    n = int(input())

    arr = list(map(int, input().split()))

    q = deque(arr)
    flag = False

    while True:
        for i in range(1, 6):
            value = q.popleft() - i
            if value <= 0:
                value = 0
                flag = True
            q.append(value)

            if flag:
                break
        if flag:
            break

    answer = ' '.join(map(str, q))

    print("#" + str(test_cases) + " " + str(answer))