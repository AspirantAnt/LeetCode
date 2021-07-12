import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    Set<String> dict = new HashSet<>();

    public boolean wordBreak(String s, List<String> wordDict) {
        dict.addAll(wordDict);
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int step = 0; step < len; step++) {
            for (int i = 0; i + step < len; i++) {
                dp[i][i + step] = dict.contains(s.substring(i, i + step + 1));
                if (!dp[i][i + step]) {
                    for (int n = i; n < i + step; n++) {
                        if (dp[i][n] && dp[n + 1][i + step]) {
                            dp[i][i + step] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][len - 1];
    }
}