#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int result;
        int difference;
        bool hasOne = false;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                cout << nums[i] << " " << nums[left] << " " << nums[right];
                int tmp_result = nums[i] + nums[left] + nums[right];
                if (!hasOne) {
                    result = tmp_result;
                    difference = abs(tmp_result - target);
                } else if (abs(tmp_result - target) < difference) {
                    result = tmp_result;
                    difference = abs(tmp_result - target);
                    hasOne = true;
                }
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else if (sum == target) {
                    return sum;
                }
            }
        }
        return result;
    }
};