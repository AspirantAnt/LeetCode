#include <iostream>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int dp = 0;
        if (s.size() == 0)
            return dp;
        char pre = s[0];
        int sum = 1;
        int pre_sum = sum;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == pre)
            {
                sum++;
                if (sum <= pre_sum)
                {
                    dp = dp + 1;
                }
            }
            else
            {
                pre = s[i];
                pre_sum = sum;
                sum = 1;
                dp = dp + 1;
            }
        }
        return dp;
    }
};