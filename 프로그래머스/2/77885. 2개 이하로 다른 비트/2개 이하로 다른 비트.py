def solution(numbers):
    answer = []
    
    for number in numbers:
        if number % 2 == 0:
            answer.append(number + 1)
            continue
        
        
        n = bin(number)
        string = ('0' + str(n)[2:])[::-1]
        idx = 0
        for i in range(1, len(string)):
            if string[i-1] == '1' and string[i] == '0':
                idx = i
                break
        answer.append(number - pow(2, idx-1) + pow(2, idx))
        
    
    return answer