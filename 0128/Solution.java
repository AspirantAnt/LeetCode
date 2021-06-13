import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        int size = nums.length;
        if (size == 0) {
            return 0;
        }
        Set<Integer> hashSet = new HashSet<>();
        int result = 1;

        for (int num : nums) {
            hashSet.add(num);
        }

        for (int num : hashSet) {
            if (!hashSet.contains(num + 1)) {
                int left = num - 1;
                int len = 1;
                while (hashSet.contains(left)) {
                    len++;
                    left--;
                }
                result = Math.max(result, len);
            }
        }
        return result;
    }
}