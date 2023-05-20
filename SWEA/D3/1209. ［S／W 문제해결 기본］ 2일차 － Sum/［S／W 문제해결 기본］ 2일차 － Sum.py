for test_cases in range(1, 11):
    answer = 0

    n = int(input())

    arr = []
    for i in range(100):
        temp = list(map(int, input().split()))
        arr.append(temp)

        answer = max(answer, sum(temp))

    for i in range(100):
        temp = 0
        for j in range(100):
            temp += arr[j][i]

        answer = max(answer, temp)

    temp = 0
    for i in range(100):
        temp += arr[i][i]

    answer = max(answer, temp)

    temp = 0
    for i in range(100):
        temp += arr[99-i][i]

    answer = max(answer, temp)

    print("#" + str(test_cases) + " " + str(answer))