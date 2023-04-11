def solution(book_time):
    answer = 0
    
    bList = []
    
    room = 0
    for b in book_time:
        sh, sm = b[0].split(':')
        eh, em = b[1].split(':')
        st = int(sh) * 60 + int(sm)
        et = int(eh) * 60 + int(em) + 10
        
        bList.append([st, 1])
        bList.append([et, -1])
    
    bList = sorted(bList)
    
    for b in bList:
        room += b[1]
        answer = max(answer, room)
    
    return answer