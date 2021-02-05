import java.util.LinkedList;
import java.util.Queue;

// 力扣第1208题
public class 尽可能使字符串相等 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abcd";
        String t = "cdef";
        System.out.println(solution.equalSubstring(s, t, 3));
    }
}

class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int len = s.length();
        if (len != t.length()) {
            return 0;
        }

        int maxLen = 0; // 最长

        int count = 0;
        Queue<Integer> q1 = new LinkedList<Integer>();
        for (int i = 0; i < len; i++) {
            int num = Math.abs(s.charAt(i) - t.charAt(i));
            q1.add(num);
            count += num;
            if (count > maxCost) {
                count -= q1.remove();
            } else {
                maxLen++;
            }
        }

        return maxLen;
    }
}