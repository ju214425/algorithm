def solution(points, routes):
    answer = 0

    collide = dict()
    
    for route in routes:
        time = -1
        
        for i in range(len(route)-1):
            depart, arrive = points[route[i]-1], points[route[i+1]-1]

            x, y = depart[0], depart[1]

            while x != arrive[0] or y != arrive[1]:

                time += 1
                if (time, x, y) in collide:
                    collide[(time, x, y)] += 1
                else:
                    collide[(time, x, y)] = 1
                
                if x > arrive[0]:
                    x -= 1
                elif x < arrive[0]:
                    x += 1
                elif y > arrive[1]:
                    y -= 1
                elif y < arrive[1]:
                    y += 1
            
        time += 1
        if (time, x, y) in collide:
            collide[(time, x, y)] += 1
        else:
            collide[(time, x, y)] = 1
                
    for key in collide:
        if collide[key] > 1:
            answer += 1
            
    return answer