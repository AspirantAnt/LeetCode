// 1-n 行以此遍历

#include "./myheaders.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        int basic = 1;
        int result = 0;
        while (basic <= row) { // 每次增加一行
            for (int i = 0; (i + basic - 1) < row; i++) {
                int area = 0;
                for (int j = 0; j < col; j++) {
                    bool match = true;
                    for (int k = i; k <= (i + basic - 1); k++) {
                        if (matrix[k][j] == '0') {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        // cout << "match: " << j << endl;
                        area += basic;
                    } else {
                        if (area > result) {
                            result = area;
                            // cout << "i: " << i << " basic: " << basic << endl;
                        }
                        area = 0;
                    }
                }
                if (area > result)
                    result = area;
            }
            basic++;
        }
        return result;
    }
};