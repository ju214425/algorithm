def solution(cards):
    answer = 0
    
    visited = [False for _ in range(len(cards)+1)]
    
    c = []
    
    for card in cards:
        if visited[card] == False:
            visited[card] = True
            cnt = 1
            next_card = cards[card-1]
            while visited[next_card] == False:
                visited[next_card] = True
                cnt += 1
                next_card = cards[next_card-1]
            c.append(cnt)

    if len(c) == 1:
        answer = 0
    else:
        c = sorted(c)
        answer = c[-1] * c[-2]
    
    
    return answer