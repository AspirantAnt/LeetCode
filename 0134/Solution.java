class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        int len = gas.length;

        for (int i = 0; i < len; ) {
            int left = 0;
            boolean flag = true;
            int n = 0;
            for (n = 0; n < len; n++) {
                left = left + gas[(i + n) % len] - cost[(i + n) % len];
                if (left < 0) {
                    break;
                }
            }
            if (n == len) {
                return i;
            } else {
                // 如果不能通过，那么i + n 之前的都不行，那么就要从i + n + 1开始进行尝试
                i = i + n + 1;
            }
        }
        return -1;
    }
}