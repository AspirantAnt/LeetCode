#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> v(numRows, "");
        int cursor = 0, nowRow = 0;
        int goDown = 1;
        for (; cursor < s.length(); cursor++) {
            v[nowRow] += s[cursor];
            if ((nowRow + goDown) == -1 || (nowRow + goDown) == numRows)
                goDown = -goDown; // Switch the direct
            nowRow += goDown;
        }
        string result = "";
        for (string each : v) {
            result += each;
        }
        return result;
    }
};