#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) return;
        int index = nums.size() - 1;
        bool decreased = false;
        for (int i = index - 1; i >= 0; i--) {
            if (nums[i] < nums[index]) {
                decreased = true;
                break;
            }
            index = i;
        }
        // 不存在下一个更大的排列
        if (index == 0 && !decreased) {
            sort(nums.begin(), nums.end());
        }
        int left = index - 1;
        while (left >= 0) {
            int i;
            for (i = nums.size() - 1; i >= index; i--) {
                if (nums[i] > nums[left]) {
                    swap(nums[i], nums[left]);
                    sort(nums.begin() + index, nums.end());
                    return;
                }
            }
            if (i < index) left--;
        }
        return;
    }
};

int main() { return 0; }