#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        if (nums.size() == 1) {
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }
        vector<int> result = {-1, -1};
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return this->getRange(nums, target, mid);
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return result;
    }

  private:
    vector<int> getRange(vector<int> nums, int target, int oneOfThem) {
        int left;
        for (left = oneOfThem; left >= 0 && nums[left] == target; left--) {}
        int right;
        for (right = oneOfThem; right < nums.size() && nums[right] == target; right++) {}
        return {left + 1, right - 1};
    }
};