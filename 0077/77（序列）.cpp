#include "./myheaders.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;

        if (n < 1 || k > n) return result;
        vector<int> nums;
        for (int i = 0; i < k; i++) nums.push_back(i + 1);
        nums.push_back(n + 1);

        int j = 0;
        while (j < k) { // k是哨兵位
            nums.pop_back();
            result.push_back(nums);
            nums.push_back(n + 1);
            j = 0;
            while (j < k && nums[j] + 1 == nums[j + 1]) {
                nums[j] = j + 1;
                j++;
            }
            nums[j] += 1;
        }
        return result;
    }
};