#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (!n)
            return result;
        int direct = 0; // 0 right, 1 down, 2 left, 3 up
        result[0][0] = 1;
        int ilast = 0, jlast = 1;
        for (int i = 1; i < n * n; i++) {
            result[ilast][jlast] = i + 1;
            if (direct == 0) {
                if (jlast == n - 1 || result[ilast][jlast + 1] != 0) {
                    direct = 1;
                    ilast++;
                } else
                    jlast++;
            } else if (direct == 1) {
                if (ilast == n - 1 || result[ilast + 1][jlast] != 0) {
                    direct = 2;
                    jlast--;
                } else
                    ilast++;
            } else if (direct == 2) {
                if (jlast == 0 || result[ilast][jlast - 1] != 0) {
                    direct = 3;
                    ilast--;
                } else
                    jlast--;
            } else if (direct == 3) {
                if (ilast == 0 || result[ilast - 1][jlast] != 0) {
                    direct = 0;
                    jlast++;
                } else
                    ilast--;
            }
        }
        return result;
    }
};

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        vector<vector<int>> result = Solution().generateMatrix(n);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}