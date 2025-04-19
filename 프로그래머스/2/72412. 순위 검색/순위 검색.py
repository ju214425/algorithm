from itertools import combinations
from collections import defaultdict
from bisect import bisect_left

def solution(info, query):
    answer = []
    info_hash = defaultdict(list)

    for i in info:
        splited_info = i.split()
        score = splited_info.pop()
        for r in range(5):
            combs = combinations(range(4), r)

            for comb in combs:
                key = splited_info[:]
                for elem in comb:
                    key[elem] = '-'

                info_hash[''.join(key)].append(int(score))

    for item in info_hash:
        info_hash[item].sort()
    
    for q in query:
        q = q.replace('and ', '').split()
        q1 = ''.join(q[:-1])
        score = int(q[-1])

        answer.append(len(info_hash[q1]) - bisect_left(info_hash[q1], score))
        
    return answer
    