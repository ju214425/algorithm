import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        HashMap<String, Integer> cache = new HashMap<>();
        
        int idx = 0;
        
        if(cacheSize == 0) {
            return cities.length * 5;
        }
        
        for(String city : cities) {
            city = city.toLowerCase();
            
            if(cache.containsKey(city)) {
                cache.put(city, idx);
                idx--;
                answer++;
            } else {
                if(cache.size() >= cacheSize) {
                    int maximum = -1000000;
                    String maximumKey = "";
                    
                    for(String key : cache.keySet()) {
                        if(maximum < cache.get(key)) {
                            maximum = cache.get(key);
                            maximumKey = key;
                        }
                    }
                    
                    cache.remove(maximumKey);
                }
                
                cache.put(city, idx);
                idx--;
                
                answer += 5;
            }
        }
        
        return answer;
    }
}