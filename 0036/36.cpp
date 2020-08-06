#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << endl;
                if (board[i][j] == '.') continue;
                // row
                if (row[i][board[i][j]]) return false;
                // col
                if (col[j][board[i][j]]) return false;
                // box
                if (box[(i / 3) * 3 + j / 3][board[i][j]]) return false;
                // row
                row[i][board[i][j]] = true;
                // col
                col[j][board[i][j]] = true;
                // box
                box[(i / 3) * 3 + j / 3][board[i][j]] = true;
            }
        }
        return true;
    }
};