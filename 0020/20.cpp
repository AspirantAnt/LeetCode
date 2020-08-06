#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<char> brackets;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
                continue;
            }
            if (brackets.empty()) return false;
            if (s[i] == ')') {
                char tmp = brackets.top();
                if (tmp == '(')
                    brackets.pop();
                else
                    return false;
            } else if (s[i] == ']') {
                char tmp = brackets.top();
                if (tmp == '[')
                    brackets.pop();
                else
                    return false;
            } else if (s[i] == '}') {
                char tmp = brackets.top();
                if (tmp == '{')
                    brackets.pop();
                else
                    return false;
            }
        }
        if (brackets.empty()) return true;
        return false;
    }
};