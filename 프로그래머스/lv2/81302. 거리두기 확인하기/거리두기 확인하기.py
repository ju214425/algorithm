from queue import *

def solution(places):
    answer = []
    
    delta = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    
    for place in places:
        people = []
        ans = True
        for row in range(5):
            for col in range(5):
                if place[row][col] == 'P':
                    people.append([row, col])
        
        for person in people:
            if ans == False:
                 break
                    
            x = person[0]
            y = person[1]
            dist = 0
            q = Queue()
            q.put([x, y, dist])
            
            while(not q.empty()):
                f = q.get()
                
                if ans == False:
                    break
                    
                for d in delta:
                    nx = f[0] + d[0]
                    ny = f[1] + d[1]
                    nd = f[2] + 1
                    
                    if 0 <= nx and nx < 5 and 0 <= ny and ny < 5 and nd <= 2 and (nx != x or ny != y):
                        if place[nx][ny] == 'O':
                            q.put([nx, ny, nd])
                            
                        elif place[nx][ny] == 'P':
                            ans = False
                            break
                            
        if ans == True :
            answer.append(1)
        else :
            answer.append(0)
            
    return answer