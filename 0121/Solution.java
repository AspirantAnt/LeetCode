class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        int minPrice = prices[0];
        int result = 0;
        for (int i = 1; i < len; i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > result) {
                result = prices[i] - minPrice;
            }
        }
        return result;
    }
}