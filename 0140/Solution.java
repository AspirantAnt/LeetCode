import java.util.*;

class Solution {
    int len;
    Set<String> dict;
    List<String> result;

    public List<String> wordBreak(String s, List<String> wordDict) {
        len = s.length();
        dict = new HashSet<>(wordDict);
        result = new ArrayList<>();

        dfs(s, 0, "");

        return result;
    }

    public void dfs(String s, int start, String ans) {
        if (start >= len) {
            result.add(ans);
            return;
        }

        for (int i = start; i < len; i++) {
            if (dict.contains(s.substring(start, i + 1))) {
                if (ans.length() != 0 && ans.charAt(ans.length() - 1) != ' ') {
                    ans = ans + " ";
                }
                ans = ans + s.substring(start, i + 1);
                dfs(s, i + 1, ans);
                ans = ans.substring(0, ans.length() - (i - start + 1));
            }
        }
    }
}