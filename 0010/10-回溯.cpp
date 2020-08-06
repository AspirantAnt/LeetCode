#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        cout << s << " " << p << endl;
        if (p.empty())
            return s.empty();
        bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2, p.length() - 2)) || (firstMatch && isMatch(s.substr(1, s.length() - 1), p)));
        } else {
            return (firstMatch && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)));
        }
    }
};

int main()
{
    cout << Solution().isMatch("aa", "a*") << endl;
    return 0;
}