def compress(s, l):
    cnt = 1
    compressed_list = []
    compressed_string = ''
    for i in range(0, len(s), l):
        compressed_list.append(s[i:i+l])
    
    for i in range(len(compressed_list)-1):
        if compressed_list[i] == compressed_list[i+1]:
            cnt += 1
        else:
            if cnt == 1:
                compressed_string += compressed_list[i]
            else:
                compressed_string += str(cnt) + compressed_list[i]
            cnt = 1

    if cnt == 1:
        compressed_string += compressed_list[-1]
    else:
        compressed_string += str(cnt) + compressed_list[-1]
    
    return compressed_string
            
def solution(s):
    answer = len(s)
    
    for i in range(1, len(s)):
        answer = min(answer, len(compress(s, i)))
    
    return answer