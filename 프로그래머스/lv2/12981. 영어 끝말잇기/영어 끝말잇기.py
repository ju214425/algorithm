def solution(n, words):
    answer = [0, 0]

    l = [words[0]]
    
    for i in range(1, len(words)):
        if words[i][0] != words[i-1][-1] or words[i] in l:
            answer = [i % n + 1, i // n + 1]
            break
        else:
            l.append(words[i])

    return answer