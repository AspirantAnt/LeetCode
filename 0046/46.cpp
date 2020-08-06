#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int> &nums) {
        int len = nums.size();
        vector<bool> used(len);
        vector<int> tmp;
        for (int i = 0; i < len; i++) {
            tmp.push_back(nums[i]);
            used[i] = true;
            backrack(nums, used, tmp);
            tmp.pop_back();
            used[i] = false;
        }
        return result;
    }

  private:
    void backrack(vector<int> nums, vector<bool> used, vector<int> tmp) {
        if (tmp.size() == nums.size()) {
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == tmp) return;
            }
            result.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            tmp.push_back(nums[i]);
            used[i] = true;
            backrack(nums, used, tmp);
            tmp.pop_back();
            used[i] = false;
        }
    }
};