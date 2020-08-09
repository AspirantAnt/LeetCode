#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    set<string> result_set;
    // ans 递归得到的答案，s 剩下的字符串， rest_num 剩下需要匹配的数字个数
    void choice_number(string ans, string s, int rest_num)
    {

        // 成功得到
        if (rest_num == 0 && s.size() == 0)
        {
            result_set.insert(ans);
        }
        int len = s.size();
        int min_len = len - (rest_num - 1) * 3;
        if (min_len <= 0)
        {
            min_len = 1;
        }
        int max_len = len - (rest_num - 1) * 1;
        for (int i = min_len; i <= max_len; i++)
        {
            int sum = 0;
            for (int n = 0; n < i; n++)
            {
                sum = sum * 10 + (s[n] - '0');
            }
            int min_num = pow(10, i - 1);
            if (sum > 255 || (sum < min_num && i > 1))
            {
                break;
            }
            else
            {
                string tmp_ans = ans;
                for (int n = 0; n < i; n++)
                {
                    tmp_ans = tmp_ans + s[n];
                }
                if (rest_num != 1)
                {
                    tmp_ans = tmp_ans + '.';
                }
                choice_number(tmp_ans, s.substr(i, len - i), rest_num - 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        int len = s.size();
        vector<string> result;

        // 没有可能情况
        if (len < 4 || len > 12)
        {
            return result;
        }

        // 非满情况
        choice_number("", s, 4);
        for (auto iter = result_set.begin(); iter != result_set.end(); iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }
};