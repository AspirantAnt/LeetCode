#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->combinationSearch(candidates, target, 0, vector<int>(), 0);
        return result;
    }

  private:
    void combinationSearch(vector<int> candidates, int target, int sum, vector<int> nums, int index) {
        if (sum == target) {
            this->result.push_back(nums);
            return;
        }
        if (sum > target) { return; }
        int len = candidates.size();
        for (int i = index; i < len; i++) {
            sum += candidates[i];
            vector<int> tmp = nums;
            tmp.push_back(candidates[i]);
            combinationSearch(candidates, target, sum, tmp, i);
            sum -= candidates[i];
        }
    }
};