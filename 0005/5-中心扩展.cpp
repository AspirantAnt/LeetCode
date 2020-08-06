#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#define max(x, y) (x) > (y) ? (x) : (y)
// expand around from center
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (!s.length())
            return s;
        int start = -1;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < maxLen / 2)
                continue;
            else if (i > s.length() - 1 - maxLen / 2)
                return s.substr(start, maxLen);
            int len1;
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            len1 = right - left - 1;
            int len2;
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            len2 = right - left - 1;
            int len = max(len1, len2);
            if (maxLen < len) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    DWORD start_time = GetTickCount();
    string result = Solution().longestPalindrome("abccba");
    DWORD end_time = GetTickCount();
    cout << end_time - start_time << " ms" << endl;
    cout << result << endl;
    return 0;
}