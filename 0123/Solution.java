public class Solution {
    public int maxProfit(int[] prices) {
        // 可以把buy1 buy2 sell1 sell2 都当成了进行买卖操作之后手里的钱的数量
        // 假设一开始钱为0，因此buy1 buy2 操作都是0-当前的价格，也就是-当前的价格
        int buy1 = -prices[0];
        int buy2 = -prices[0];
        // 由于卖出之后手里的钱最少最少为0，因为如果亏本的话就可以不买卖
        int sell1 = 0;
        int sell2 = 0;
        int len = prices.length;
        for (int i = 1; i < len; i++) {
            // 如果第一次是在当前买入的话，比较之前买入之后手里的钱和现在买手里钱的大小
            buy1 = Math.max(buy1, - prices[i]);
            // 如果是在当前卖出的话，比较卖出得到的利润和之前卖出的利润的比较
            sell1 = Math.max(sell1, buy1 + prices[i]);
            // 同上
            buy2 = Math.max(buy2, sell1 - prices[i]);
            // 同上
            sell2 = Math.max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
}