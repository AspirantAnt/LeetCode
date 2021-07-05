import java.util.Arrays;

class Solution {
    public int minCut(String s) {
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            Arrays.fill(dp[i], true);
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                dp[i][j] = dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j);
            }
        }

        int[] result = new int[len];
        Arrays.fill(result, Integer.MAX_VALUE);

        for (int i = 0; i < len; i++) {
            // 如果这整个字符串是回文
            if (dp[0][i]) {
                result[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (dp[j + 1][i])
                        result[i] = Math.min(result[i], result[j] + 1);
                }
            }
        }

        return result[len - 1];

    }
}