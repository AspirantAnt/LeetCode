#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) return len;
        int last_num = nums[0];
        for (int i = 1; i < len;) {
            if (nums[i] == last_num) {
                nums.erase(nums.begin() + i);
                len--;
            } else {
                last_num = nums[i];
                i++;
            }
        }
        return nums.size();
    }
};