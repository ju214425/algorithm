def solution(cacheSize, cities):
    answer = 0
    
    cache = {}
    
    idx = 0
    
    if cacheSize == 0:
        return len(cities) * 5
    
    
    for city in cities:
        city = city.lower()
        if city in cache:
            cache[city] = idx
            idx -= 1
            answer += 1
            
        else:
            if len(cache) >= cacheSize:
                maximum = -1000000
                maximumKey = ""
                for key in cache:
                    if maximum < cache[key]:
                        maximum = cache[key]
                        maximumKey = key
                
                del(cache[maximumKey])
                
            cache[city] = idx
            idx -= 1
            
            answer += 5
    
    return answer