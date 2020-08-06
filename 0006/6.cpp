#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        string result = "";
        if (numRows == 1)
            return s;
        int step = (numRows - 1) * 2;
        for (int i = 0; i < s.length(); i += step) {
            result += s[i];
            cout << s[i];
        }
        for (int row = 1; row < numRows - 1; row++) {
            // 输入z 转换的第row + 1 行
            for (int i = row; i < s.length() || (i - row * 2) < s.length(); i += step) {

                if ((i - row * 2) > 0) {
                    result += s[(i - row * 2)];
                    cout << s[(i - row * 2)];
                }
                if (i < s.length()) {
                    result += s[i];
                    cout << s[i];
                }
            }
        }
        for (int i = numRows - 1; i < s.length(); i += step) {
            result += s[i];
            cout << s[i];
        }
        return result;
    }
};
// (1)
// 1 7 13 (6)
// 1 5 9 13 17 (4)
// 1 9
// (numRows-1)*2

// (2+)
// 2 8 14 (6)
// (numRows-1)*2