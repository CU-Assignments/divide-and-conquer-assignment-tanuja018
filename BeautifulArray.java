import java.util.*;
class Solution {
    public int[] beautifulArray(int n) {
        List<Integer> result = new ArrayList<>();
        result.add(1);
        
        while (result.size() < n) {
            List<Integer> temp = new ArrayList<>();
            for (int num : result) {
                if (num * 2 - 1 <= n) temp.add(num * 2 - 1); 
            }
            for (int num : result) {
                if (num * 2 <= n) temp.add(num * 2);  
            }
            result = temp;
        }
        
        int[] beautifulArray = new int[n];
        for (int i = 0; i < n; i++) {
            beautifulArray[i] = result.get(i);
        }
        
        return beautifulArray;
    }
}
