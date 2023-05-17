def solution(record):
    answer = []
    member = {}
    temp = []
    for line in record:
        data = line.split()
        if data[0] == 'Enter':
            member[data[1]] = data[2]
            temp.append([data[1], 0])
        if data[0] == 'Leave':
            temp.append([data[1], 1])
        if data[0] == 'Change':
            member[data[1]] = data[2]
        
    
    for line in temp:
        if line[1] == 0 :
            answer.append(member[line[0]] + '님이 들어왔습니다.')
        elif line[1] == 1 :
            answer.append(member[line[0]] + '님이 나갔습니다.')
    return answer