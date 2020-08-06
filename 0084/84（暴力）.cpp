#include "./myheaders.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int cnt = heights.size();
        if (cnt == 0)
            return 0;
        vector<vector<int>> minLen(cnt, vector<int>(cnt, 0));
        int result = heights[0];
        // init dp array
        for (int i = 0; i < cnt; i++)
            minLen[i][i] = heights[i];
        for (int i = 0; i < cnt; i++) {
            for (int j = i; j < cnt; j++) {
                if (i != j)
                    minLen[i][j] = min(minLen[i][j - 1], heights[j]);
                int tmp = (j - i + 1) * minLen[i][j];
                if (result < tmp)
                    result = tmp;
            }
        }
        return result;
    }
};