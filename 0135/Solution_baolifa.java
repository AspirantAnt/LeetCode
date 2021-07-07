class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return 1;
        }

        int[] dp = new int[len];
        dp[0] = 1;

        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else if (ratings[i] < ratings[i - 1]) {
                dp[i] = 1;
                for (int j = i; j > 0; j--) {
                    if (dp[j - 1] != dp[j] || ratings[j - 1] == ratings[j]) {
                        break;
                    }
                    dp[j - 1]++;
                }
            } else {
                if (dp[i - 1] == 1 && i + 1 < len && ratings[i + 1] < ratings[i]) {
                    dp[i] = 2;
                } else {
                    dp[i] = 1;
                }
            }
        }

        int result = 0;
        for (int i : dp) {
            System.out.print(i + " ");
            result += i;
        }

        return result;

    }
}