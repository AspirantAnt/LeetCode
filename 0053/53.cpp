#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int len = nums.size();
        int result = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i - 1] > 0) nums[i] = nums[i - 1] + nums[i];
            result = max(nums[i], result);
        }
        return result;
    }
};