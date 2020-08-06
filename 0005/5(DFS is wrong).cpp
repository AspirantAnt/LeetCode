#include <iostream>
#include <string>
using namespace std;
// DFS Stack
class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        bool flag = true;
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - i - 1]) {
                flag = false;
            }
        }
        if (flag)
            return s;
        else {
            string s1 = longestPalindrome(s.substr(1, len - 1));
            string s2 = longestPalindrome(s.substr(0, len - 2));
            return s1.length() >= s2.length() ? s1 : s2;
        }
    }
};