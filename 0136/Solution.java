class Solution {
    public int singleNumber(int[] nums) {
        int len = nums.length;
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
}