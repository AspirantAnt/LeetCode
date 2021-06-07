class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        int result = 0;
        for (int i = 1; i < len; i++) {
            result += Math.max(0, prices[i] - prices[i-1]);
        }
        return result;
    }
}