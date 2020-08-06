#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.length() == 0 || s.length() == 1) return 0;
        int len = s.length();
        int slen = len;
        if (slen % 2 != 0) slen--;
        while (slen > 1) {
            cout << slen << endl;
            int i;
            for (i = 0; i < len - slen + 1;) {
                cout << "i: " << i << endl;
                stack<char> brackets;
                int n;
                for (n = i; n < i + slen; n++) {
                    if (s[n] == '(')
                        brackets.push(s[n]);
                    else {
                        if (brackets.empty() || brackets.top() != '(') {
                            i = n;
                            break;
                        }
                        brackets.pop();
                    }
                }
                if (n == (i + slen) && brackets.empty()) return slen;
                i++;
            }
            slen -= 2;
        }
        return 0;
    }
};

int main() {
    cout << Solution().longestValidParentheses(")()())");
    return 0;
}