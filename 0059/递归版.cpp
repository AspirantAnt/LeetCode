#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n, int direct, int x, int y, int num,
                                   vector<vector<int>> matrix) {
    if (num > n * n)
        return matrix;
    matrix[x][y] = num++;
    if (direct == 0) { // right
        if ((y + 1) >= n || matrix[x][y + 1] != 0) {
            x++;
            direct++;
        } else
            y++;
    } else if (direct == 1) { // down
        if ((x + 1) >= n || matrix[x + 1][y] != 0) {
            y = y - 1;
            direct++;
        } else
            x++;
    } else if (direct == 2) { // left
        if ((y - 1) < 0 || matrix[x][y - 1] != 0) {
            x = x - 1;
            direct++;
        } else
            y--;
    } else if (direct == 3) { // up
        if ((x - 1) < 0 || matrix[x - 1][y] != 0) {
            y++;
            direct++;
        } else
            x--;
    }
    return generateMatrix(n, direct % 4, x, y, num, matrix);
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        vector<vector<int>> result = vector<vector<int>>(n, vector<int>(n, 0));
        result = generateMatrix(n, 0, 0, 0, 1, result);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}