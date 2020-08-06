#include "./myheaders.h"

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int len = nums.size();
        if (len == 0) return false;

        int pos;
        for (pos = 1; pos < len && nums[pos] >= nums[pos - 1]; pos++) { }

        cout << "pos " << pos << endl;
        int left = 0, right = len - 1;
        int x, y, mid;
        if (nums[left] <= target && target <= nums[pos - 1]) {
            x = left, y = pos - 1;
        } else if (pos <= right && nums[pos] <= target && target <= nums[right]) {
            x = pos, y = right;
        } else
            return false;
        while (x <= y) {
            mid = (x + y) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                x = mid + 1;
            else
                y = mid - 1;
        }
        return false;
    }
};