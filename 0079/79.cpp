#include "./myheaders.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0) return len;
        unordered_map<int, int> umap;
        for (int i = 0; i < len;) {
            if (umap[nums[i]] < 2) {
                umap[nums[i]]++;
                i++;
            } else {
                nums.erase(nums.begin() + i);
                len--;
            }
        }
        return len;
    }
};