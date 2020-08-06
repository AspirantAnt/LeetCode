#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int len = matrix.size() - 1;
        for (int i = 0; i <= len; i++) {
            for (int j = i; j <= len; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        int mid = len / 2;
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= mid; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][len - j];
                matrix[i][len - j] = tmp;
            }
        }
    }
};