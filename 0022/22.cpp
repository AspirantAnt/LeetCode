#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        f1("", 0, n);
        return result;
    }

  private:
    void f1(string brackets, int leftBrackets, int n) {
        if (n == 0) {
            result.push_back(brackets);
            return;
        }
        if (leftBrackets < n) {
            f1(brackets + '(', leftBrackets + 1, n);
        }
        if (leftBrackets > 0) {
            f1(brackets + ')', leftBrackets - 1, n - 1);
        }
        return;
    }
};