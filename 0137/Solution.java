import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    public int singleNumber(int[] nums) {
        int len = nums.length;
        HashMap<Integer, Integer> numToTimes = new HashMap<>();
        for (int i = 0; i < len; i++) {
            Integer times = numToTimes.putIfAbsent(nums[i], 1);
            if (times != null) {
                numToTimes.put(nums[i], times + 1);
            }
        }
        for (Integer integer : numToTimes.keySet()) {
            if(numToTimes.get(integer) == 1) {
                return integer;
            }
        }
        return -1;
    }
}