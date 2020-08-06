// 记录当前高度

#include "./myheaders.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        int result = 0;
        for (int i = 0; i < row; i++) {
            // update height
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1')
                    heights[j] = heights[j] + 1;
                else
                    heights[j] = 0;
                // cout << heights[j] << " ";
            }
            // cout << endl;
            // 遍历每个点，都拓展一遍
            for (int j = 0; j < col; j++) {
                // 向左拓展
                int left = j, right = j;
                while (left >= 0) {
                    if (heights[left] >= heights[j])
                        left--;
                    else
                        break;
                }
                left++;
                // 向右拓展
                while (right < col) {
                    if (heights[right] >= heights[j])
                        right++;
                    else
                        break;
                }
                right--;

                // calc area;
                int area = (right - left + 1) * heights[j];
                if (area > result)
                    result = area;
            }
        }
        return result;
    }
};