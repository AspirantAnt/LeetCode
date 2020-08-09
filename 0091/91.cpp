#include <iostream>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int len = s.size();
        if (len == 0)
        {
            return 0;
        }
        if (s[0] == '0')
        {
            return 0;
        }
        if (len == 1)
        {
            return 1;
        }
        int pre = 1, cur = 1;
        for (int i = 1; i < len; i++)
        {
            int tmp = cur;
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    cur = pre;
                }
                else
                {
                    return 0;
                }
            }
            else if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            {
                cur = cur + pre;
            }
            pre = tmp;
        }
        return cur;
    }
};