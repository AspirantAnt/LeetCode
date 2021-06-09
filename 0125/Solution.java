public class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        char[] str = s.toCharArray();

        for (int i = 0, j = len - 1; i <= j; ) {
            boolean flag = false;
            if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')) {
                i++;
                flag = true;
            }
            if (!(str[j] >= '0' && str[j] <= '9') && !(str[j] >= 'a' && str[j] <= 'z') && !(str[j] >= 'A' && str[j] <= 'Z')) {
                j--;
                flag = true;
            }
            if (!flag) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] = (char) (str[i] - 'A' + 'a');
                }
                if (str[j] >= 'A' && str[j] <= 'Z') {
                    str[j] = (char) (str[j] - 'A' + 'a');
                }
                if (str[i] != str[j]) {
                    return false;
                }
                i++;
                j--;
            }

        }
        return true;
    }
}
