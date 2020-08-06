#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')')
                right++;
            if (left == right) {
                maxlen = max(maxlen, left * 2);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')')
                right++;
            if (left == right) {
                maxlen = max(maxlen, left * 2);
            } else if (right < left) {
                left = right = 0;
            }
        }
        return maxlen;
    }
};

int main() {
    cout << Solution().longestValidParentheses(")()())");
    return 0;
}