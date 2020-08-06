#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int len = intervals.size();
        for (int i = 0; i <= len; i++) {
            if (i == len) {
                for (int n = 0; n <= len; n++) {
                    if (n == len)
                        intervals.push_back(newInterval);
                    else if (newInterval[0] <= intervals[n][0]) {
                        intervals.insert(intervals.begin() + n, newInterval);
                        return intervals;
                    } else if (newInterval[0] > intervals[n][0])
                        continue;
                }
            }
            if (newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1])
                continue;
            else {
                int oldLeft = intervals[i][0];
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                for (int n = len - 1; n > i; n--) {
                    if (intervals[n][1] < intervals[i][0] || intervals[n][0] > intervals[i][1])
                        continue;
                    else {
                        intervals[i][0] = min(intervals[i][0], intervals[n][0]);
                        intervals[i][1] = max(intervals[i][1], intervals[n][1]);
                        intervals.erase(intervals.begin() + n);
                    }
                }
                if (oldLeft != intervals[i][0]) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (intervals[k][0] < intervals[i][0]) break;
                        int tmp = intervals[k + 1][0];
                        intervals[k + 1][0] = intervals[k][0];
                        intervals[k][0] = tmp;
                        tmp = intervals[k + 1][1];
                        intervals[k + 1][1] = intervals[k][1];
                        intervals[k][1] = tmp;
                    }
                }
                return intervals;
            }
        }
        return intervals;
    }
};