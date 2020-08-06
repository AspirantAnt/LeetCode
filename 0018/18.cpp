#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int n : nums)
            cout << n << ' ';
        cout << endl;
        int len = nums.size();
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = len - 1;
                while (left < right) {
                    int sum = nums[j] + nums[left] + nums[right];
                    cout << nums[i] << " " << nums[j] << " " << nums[left] << " " << nums[right] << endl;
                    if (sum > (target - nums[i]))
                        right--;
                    else if (sum < (target - nums[i]))
                        left++;
                    else {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        while (left < right && nums[left + 1] == nums[left])
                            left++;
                        left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1, -2, -5, -4, -3, 3, 3, 5 };
    vector<vector<int>> result = Solution().fourSum(nums, -11);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}