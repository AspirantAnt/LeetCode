#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasStar(string s, string p, char symbol)
    {
        int i, j;
        for (i = 0; i < s.length(); i++) {
            for (j = 0; j < p.length(); j++) {
                if (p[j] == '.' || s[i + j] == p[j])
                    continue;
                if (p[j] == '*') {
                    if (j == p.length() - 1 && p[j - 1] == '.')
                        return true;
                    return hasStar(s.substr(i + j - 1, s.length()), p.substr(j + 1, p.length()), p[j - 1]);
                }
            }
            if (j == p.length())
                return true;
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        if (s.empty() || p.empty())
            return false;
        // if no '*' in string
        if (p.find('*') == string::npos) {
            if (s.length() != p.length())
                return false;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != p[i] && p[i] != '.')
                    return false;
            }
            return true;
        } else {
            // erase the '*', than compare the length of p and s;
            string tmp = p;
            int pos;
            while ((pos = tmp.find('*')) != string::npos) {
                tmp.erase(pos - 1, 2);
            }
            if (tmp.length() > s.length())
                return false;

            // start to compare
            int i, j;
            for (i = 0, j = 0; i < s.length() && j < p.length(); i++, j++) {
                cout << i << " " << j << endl;
                // push to back;
                if (p[j] == '*') {
                    if (j == p.length() - 1 && p[j - 1] == '.')
                        return true;
                    return hasStar(s.substr(i - 1, s.length()), p.substr(j + 1, p.length()), p[j - 1]);
                }
                if (s[i] != p[j] && p[j] != '.' && ((j + 1) < p.length() && p[j + 1] != '*')) {
                    return false;
                }
                if (s[i] == p[j] || p[j] == '.')
                    continue;
            }
        }
        return false;
    }
};

int main()
{
    cout << Solution().isMatch("aab", "c*") << endl;
    return 0;
}