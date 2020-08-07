#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len == 0)
        {
            return result;
        }
        set<vector<int>> pre_result;
        pre_result.insert(result[0]);
        result.pop_back();
        for (int n = 0; n < len; n++)
        {
            set<vector<int>> tmp_set = pre_result;
            // 遍历每个tmp_set
            for (set<vector<int>>::iterator index = tmp_set.begin(); index != tmp_set.end(); index++)
            {
                // 每个都加nums[n]
                vector<int> tmp = *index;
                // 排下序
                tmp.insert(tmp.end(), nums[n]);
                pre_result.insert(tmp);
            }
        }
        for (set<vector<int>>::iterator index = pre_result.begin(); index != pre_result.end(); index++)
        {
            result.push_back((*index));
        }
        return result;
    }
};