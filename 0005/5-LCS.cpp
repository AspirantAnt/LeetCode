#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define max(x, y) (x) > (y) ? (x) : (y)
// Longest common substrng
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (!s.length())
            return s;
        string rev_s = s;
        long sum = 0;
        // get reverse string
        reverse(rev_s.begin(), rev_s.end());
        int start = -1, maxLen = 0;
        // get max substring
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < rev_s.length(); j++) {
                int nowLen = 0;
                if (maxLen >= (s.length() - j))
                    break;
                for (int n = 0; (n + j) <= rev_s.length(); n++) {
                    sum++;
                    if (rev_s[j + n] != s[i + n] || (n + j) == rev_s.length()) {
                        // exclude the spacial case, such as "accda" in "accdaoiadcca"
                        if (nowLen > maxLen && (s.length() - j - nowLen) == i) {
                            start = i;
                            maxLen = nowLen;
                            if (maxLen >= (s.length() - i - 1)) {
                                string tmp = s.substr(start, maxLen);
                                return tmp;
                            }
                        }
                        break;
                    }
                    if (rev_s[j + n] == s[i + n])
                        nowLen++;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    DWORD start_time = GetTickCount();
    string result = Solution().longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    DWORD end_time = GetTickCount();
    cout << end_time - start_time << endl;
    cout << result << endl;
    return 0;
}
// maccdaoiadccappp
// pppaccdaioadccam