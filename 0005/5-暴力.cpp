// 时间复杂度太高
#include <iostream>
#include <queue>
#include <string>
using namespace std;
// BFS Queue
class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        bool flag = true;
        for (; len > 0; len--) {
            for (int i = 0; i <= s.length() - len; i++) {
                for (int k = 0; k < len / 2; k++) {
                    if (s[k + i] != s[i + len - k - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return s.substr(i, len - 1);
                }
            }
        }
    }
};