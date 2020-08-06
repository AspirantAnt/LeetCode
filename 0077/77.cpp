#include "./myheaders.h"

class Solution {
private:
    void select(int n, int k, vector<int> nums)
    {
        if (nums.size() == k) {
            result.push_back(nums);
            return;
        }

        for (int i = nums.back() + 1; i <= n; i++) {
            nums.push_back(i);
            select(n, k, nums);
            nums.pop_back();
        }
    }

public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k)
    {
        // C n k
        if (n < 1 || k > n) return result;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            nums.push_back(i);
            select(n, k, nums);
            nums.pop_back();
        }
        return result;
    }
};