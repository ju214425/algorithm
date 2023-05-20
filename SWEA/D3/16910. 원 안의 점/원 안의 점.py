import math

t = int(input())

for test_cases in range(1, t+1):
    n = int(input())

    answer = 0

    for i in range(1, n+1):
        answer += int(math.sqrt(pow(n, 2) - pow(i, 2)))

    answer = answer * 4 + n * 4 + 1

    print("#" + str(test_cases) + " " + str(answer))