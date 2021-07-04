import java.util.ArrayList;
import java.util.List;

class Solution {
    int len;
    int[][] dp;
    List<List<String>> result;
    List<String> ans;

    public List<List<String>> partition(String s) {
        len = s.length();
        dp = new int[len][len];
        result = new ArrayList<List<String>>();
        ans = new ArrayList<>();

        dfs(s, 0);

        return result;
    }


    public void dfs(String s, int index) {
        if (index == len) {
            result.add(new ArrayList<>(ans));
            return;
        }
        for (int i = index; i < len; i++) {
            if (isPalindrome(s, index, i) == 1) {
                ans.add(s.substring(index, i + 1));
                dfs(s, i + 1);
                ans.remove(ans.size() - 1);
            }
        }
    }

    public int isPalindrome(String s, int i, int j) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        // 两种情况，当属于同一个位置的时候，或者是上一个函数i == 1 j == 2时，会出现这种情况
        else if (i >= j) {
            dp[i][j] = 1;
        } else if (s.charAt(i) == s.charAt(j)) {
            dp[i][j] = isPalindrome(s, i + 1, j - 1);
        } else {
            dp[i][j] = -1;
        }
        return dp[i][j];

    }
}