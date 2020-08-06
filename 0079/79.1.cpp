#include "./myheaders.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0) return len;
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                if (cnt == 2) {
                    cnt = 1;
                    nums.erase(nums.begin() + i);
                } else {
                    cnt++;
                }
            } else
                cnt = 1;
        }
        return len;
    }
};