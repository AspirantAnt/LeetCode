class Solution {
  public:
    int cnt = 0;
    int totalNQueens(int n) {
        // init
        vector<string> board;
        vector<bool> usedCol(n, 0);
        string tmp;
        for (int i = 0; i < n; i++, tmp += '.') {}
        for (int i = 0; i < n; i++, board.push_back(tmp)) {}

        // first row
        for (int j = 0; j < n; j++) {
            board[0][j] = 'Q';
            usedCol[j] = true;
            searchNQueens(board, n, 1, usedCol);
            board[0][j] = '.';
            usedCol[j] = false;
        }
        return cnt;
    }

  private:
    void searchNQueens(vector<string> board, int n, int i, vector<bool> usedCol) {
        if (i == n) {
            cnt++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (usedCol[j]) continue;
            bool flag = false;
            for (int ix = i, jx = j; ix >= 0 && jx >= 0; ix--, jx--) {
                if (board[ix][jx] == 'Q') {
                    flag = true;
                    break;
                }
            }
            for (int ix = i, jx = j; ix >= 0 && jx < n; ix--, jx++) {
                if (board[ix][jx] == 'Q') {
                    flag = true;
                    break;
                }
            }
            for (int ix = i, jx = j; ix < n && jx >= 0; ix++, jx--) {
                if (board[ix][jx] == 'Q') {
                    flag = true;
                    break;
                }
            }
            for (int ix = i, jx = j; ix < n && jx < n; ix++, jx++) {
                if (board[ix][jx] == 'Q') {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            board[i][j] = 'Q';
            usedCol[j] = true;
            searchNQueens(board, n, i + 1, usedCol);
            board[i][j] = '.';
            usedCol[j] = false;
        }
    }
};