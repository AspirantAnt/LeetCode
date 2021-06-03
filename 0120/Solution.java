class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        // 得到最大的数组的大小
        int maxSize = triangle.get(triangle.size() - 1).size();
        int[][] dp = new int[maxSize][maxSize];
        dp[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if(j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle.get(i).get(j);
                } else if (j == i) {
                    dp[i][j] = dp[i-1][j-1] + triangle.get(i).get(j);
                } else {
                    dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
        int result = dp[maxSize - 1][0];
        for(int num : dp[maxSize-1]){
            result = Math.min(result, num);
        }
        return result;
    }
}