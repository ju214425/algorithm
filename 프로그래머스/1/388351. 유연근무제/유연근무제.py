def solution(schedules, timelogs, startday):
    answer = len(schedules)
    
    valid = [i for i in range(startday,)]
    
    modified_timelogs = []
    
    for idx, timelog in enumerate(timelogs):
        modified_timelog = (timelog + timelog)
        time = 0
        if (schedules[idx] + 10) % 100 >= 60:
            time = (schedules[idx] // 100 + 1) * 100 + (schedules[idx]%100) - 50
        else:
            time = schedules[idx] + 10
            
        for timelog in modified_timelog[8-startday:13-startday]:
            if timelog > time:
                answer -= 1
                break
    
    
    return answer