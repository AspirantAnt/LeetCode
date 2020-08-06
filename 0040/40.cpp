#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->combinationSearch(candidates, target, 0, vector<int>(), 0);
        return result;
    }

  private:
    void combinationSearch(vector<int> candidates, int target, int sum, vector<int> nums, int index) {
        if (sum == target) {
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == nums) return;
            }
            this->result.push_back(nums);
            return;
        }
        if (sum > target) { return; }
        int len = candidates.size();
        for (int i = index; i < len; i++) {
            sum += candidates[i];
            vector<int> tmp = nums;
            tmp.push_back(candidates[i]);
            combinationSearch(candidates, target, sum, tmp, i + 1);
            sum -= candidates[i];
        }
    }
};