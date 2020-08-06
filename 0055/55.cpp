#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int end = 0, maxPosition = 0, len = nums.size();
        for (int i = 0; i < len && i <= end; i++) {
            if (maxPosition >= len - 1) return true;
            maxPosition = max(maxPosition, i + nums[i]);
            if (end == i) end = maxPosition;
        }
        return false;
    }
};