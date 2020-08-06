#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int direction = 0; // 0 右，1 下，2 左，3下 对4求余后
        for (int i = 0, j = 0;;) {
            visited[i][j] = true;
            result.push_back(matrix[i][j]);
            if (result.size() == row * col) return result;
            if (direction == 0) {
                if ((j + 1) < col && !visited[i][j + 1]) {
                    j++;
                } else {
                    direction = 1;
                    i++;
                }
            } else if (direction == 1) {
                if ((i + 1) < row && !visited[i + 1][j]) {
                    i++;
                } else {
                    direction = 2;
                    j--;
                }
            } else if (direction == 2) {
                if ((j - 1) >= 0 && !visited[i][j - 1]) {
                    j--;
                } else {
                    direction = 3;
                    i--;
                }
            } else if (direction == 3) {
                if ((i - 1) >= 0 && !visited[i - 1][j]) {
                    i--;
                } else {
                    direction = 0;
                    j++;
                }
            }
        }
        return result;
    }
};