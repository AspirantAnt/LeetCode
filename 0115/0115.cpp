#include <iostream>
using namespace std;

/* 超时
class Solution
{
public:
    int result = 0;
    void function1(string s, string t, int spoint, int tpoint)
    {
        if (tpoint == t.size())
        {
            this->result++;
            return;
        }
        if (spoint >= s.size() && tpoint < t.size())
        {
            return;
        }
        if (s[spoint] == t[tpoint])
        {
            function1(s, t, spoint + 1, tpoint + 1);
        }
        function1(s, t, spoint + 1, tpoint);
    }
    int numDistinct(string s, string t)
    {
        function1(s, t, 0, 0);
        return result;
    }
};
*/

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        vector<vector<long>> dp(len2, vector<long>(len1 + 1, 0));
        int start_index = 0;
        for (int i = 0; i < len2; i++)
        {
            for (int j = 1 + start_index; j <= len1; j++)
            {
                if (s[j - 1] == t[i])
                {
                    if (i == 0)
                    {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                    else
                    {
                        if (i > 0 && t[i] == t[i - 1])
                        {
                            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                        }
                        else
                        {
                            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                        }
                    }
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    if (dp[i][j] == 0)
                    {
                        start_index++;
                    }
                }
            }
            start_index++;
        }
        // for (int i = 0; i < len2; i++)
        // {
        //     for (int j = 1; j <= len1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[len2 - 1][len1];
    }
};

int main()
{
    cout << Solution().numDistinct("babgbag", "bag") << endl;
    return 0;
}