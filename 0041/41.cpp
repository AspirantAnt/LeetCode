#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int minNum, minIndex;
        for (minIndex = 0; minIndex < nums.size() && nums[minIndex] <= 0; minIndex++) {}
        minNum = nums[minIndex];
        if (minNum > 1) return 1;
        for (minIndex = minIndex + 1; minIndex < nums.size(); minIndex++) {
            if (minNum == nums[minIndex] - 1) {
                minNum = nums[minIndex];
            } else
                return minNum + 1;
        }
        return 0;
    }
};