class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return;
        int front = 0, behind = len - 1, cur = 0;
        while (cur <= behind) {
            if (nums[cur] == 1)
                cur++;
            else if (nums[cur] == 0) {
                int tmp = nums[front];
                nums[front] = nums[cur];
                nums[cur] = tmp;
                front++;
                cur++;
            } else if (nums[cur] == 2) {
                int tmp = nums[behind];
                nums[behind] = nums[cur];
                nums[cur] = tmp;
                behind--;
            }
        }
        return;
    }
};