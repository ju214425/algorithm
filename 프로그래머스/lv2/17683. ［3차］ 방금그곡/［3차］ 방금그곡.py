def changeAtoI(info):
    t = 'a, b, c, d, e, f, g, h, i, j, k, l'.split(', ')
    f = 'C#, D#, F#, G#, A#, C, D, E, F, G, A, B'.split(', ')
    
    rep = info
    
    for a, b in zip(f, t):
        rep = rep.replace(a, str(b))
    
    return rep
    
    

def solution(m, musicinfos):
    answer = '(None)'
    
    m = changeAtoI(m)
    
    answerList = []
    for idx, music in enumerate(musicinfos):
        s, e, title, info = music.split(',')
        
        sh, sm = s.split(':')
        eh, em = e.split(':')
        
        time = (int(eh) - int(sh)) * 60 + int(em) - int(sm)
        
        info = changeAtoI(info)
        
        length = len(info)
        
        if time // length < 1:
            info = info[:time]
        else:
            info *= ((1439//length)+1)
        
        if m in info:
            answerList.append([title, time, idx])
    
    if len(answerList) != 0:
        answerList = sorted(answerList, key = lambda x : (-x[1], x[2]))
        answer = answerList[0][0]
        
    
    return answer