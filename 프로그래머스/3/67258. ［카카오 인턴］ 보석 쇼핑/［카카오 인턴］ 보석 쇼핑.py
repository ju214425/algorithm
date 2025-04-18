from collections import defaultdict

def solution(gems):
    gem_types = len(set(gems))
    gem_count = defaultdict(int)
    start, end = 0, 0
    min_length = float('inf')
    answer = [0, len(gems)-1]
    
    while end < len(gems):
        gem_count[gems[end]] += 1
        end += 1
        
        while len(gem_count) == gem_types:
            if end - start < min_length:
                min_length = end - start
                answer = [start + 1, end]  # 1-based 인덱스 변환
            
            gem_count[gems[start]] -= 1
            if gem_count[gems[start]] == 0:
                del gem_count[gems[start]]
            start += 1
    
    return answer
