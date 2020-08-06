#include <iostream>
#include <string>
#include <vector>
using namespace std;
// DP

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (!len)
            return "";
        // get the dynamic array
        vector<vector<int>> dp(len, vector<int>(len, 0));

        int maxLen = 1;
        int start = 0;
        // init the data;
        for (int i = 0; i < len - 1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                maxLen = 2;
                start = i;
            }
        }
        dp[len - 1][len - 1] = 1;

        // try the str with 'tryLen' length;
        for (int tryLen = 3; tryLen <= len; tryLen++) {
            for (int i = 0; i <= len - tryLen; i++) {
                int j = i + tryLen - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    start = i;
                    maxLen = tryLen;
                }
            }
        }
        for (int k = 0; k < len; k++) {
            for (int l = 0; l < len; l++)
                cout << dp[k][l];
            cout << endl;
        }
        return s.substr(start, maxLen);
    }
};