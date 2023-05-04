import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] sArr = s.split(" ");
        
        ArrayList<Integer> intArr = new ArrayList<Integer>();
        
        for(String str : sArr) {
            intArr.add(Integer.parseInt(str));
        }
        
        Collections.sort(intArr);
        
        answer += intArr.get(0).toString() + " ";
        answer += intArr.get(intArr.size()-1).toString();
        
        return answer;
    }
}