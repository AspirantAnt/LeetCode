#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int jump(vector<int> &nums) {
        int end = 0, maxPosition = 0, step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (end >= nums.size() - 1) return step;
            maxPosition = max(maxPosition, nums[i] + i);
            if (i == end) {
                end = maxPosition;
                step++;
            }
        }
        return step;
    }
};