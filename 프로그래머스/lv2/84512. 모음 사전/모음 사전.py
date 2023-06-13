w = ['A', 'E', 'I', 'O', 'U']

def function(arr, limit, cur, word):
    if limit == cur:
        arr.add(word)
        return
    
    for i in range(5):
        word = word + w[i]
        function(arr, limit, cur+1, word)
        word = word[:-1]

def solution(word):
    answer = 0
    
    arr = set()
    
    for i in range(1, 6):
        function(arr, i, 0, '')
    
    arr = sorted(list(arr))
    
    for idx, value in enumerate(arr):
        if value == word:
            answer = idx+1
            break
    
    return answer