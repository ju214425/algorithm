def solution(arr1, arr2):
    answer = []
    
    answer = [[0 for _ in range(len(arr2[0]))] for _ in range(len(arr1))]

                    
    for j in range(len(arr1)): 
        for k in range(len(arr2[0])):
            for i in range(len(arr1[0])):
                answer[j][k] += arr1[j][i] * arr2[i][k]
    
    return answer