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

        while (hashSet.size() != 0) {
            // 得到没有遍历的第一个数
            int cur = hashSet.iterator().next();
            hashSet.remove(cur);
            int left = cur - 1;
            int right = cur + 1;
            int len = 1;
            while (hashSet.contains(left) || hashSet.contains(right)) {
                if (hashSet.contains(left)) {
                    len++;
                    hashSet.remove(left);
                    left--;
                }
                if (hashSet.contains(right)) {
                    len++;
                    hashSet.remove(right);
                    right++;
                }
            }
            result = Math.max(result, len);
        }
        return result;
    }
}