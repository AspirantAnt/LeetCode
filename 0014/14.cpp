#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string result = "";
        if (strs.empty())
            return result;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int n = 1; n < strs.size(); n++) {
                if (strs[n][i] != strs[0][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};