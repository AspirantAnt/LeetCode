#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> result;
        int len = intervals.size();
        if (len == 0) return result;
        result.push_back(intervals[0]);
        for (int i = 1; i < len; i++) {
            for (int n = 0; n <= result.size(); n++) {
                if (n == result.size()) {
                    result.push_back(intervals[i]);
                    break;
                }
                if (intervals[i][1] < result[n][0] || intervals[i][0] > result[n][1])
                    continue;
                else {
                    result[n][0] = min(intervals[i][0], result[n][0]);
                    result[n][1] = max(intervals[i][1], result[n][1]);
                    // n 合并了，所以要把之后的和它进行检验
                    for (int k = result.size() - 1; k > n; k--) {
                        if (result[k][1] < result[n][0] || result[k][0] > result[n][1])
                            continue;
                        else {
                            result[n][0] = min(result[k][0], result[n][0]);
                            result[n][1] = max(result[k][1], result[n][1]);
                            result.erase(result.begin() + k);
                        }
                    }
                    break;
                }
            }
        }
        return result;
    }
};