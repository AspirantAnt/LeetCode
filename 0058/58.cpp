#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int i, result = 0;
        for (i = len - 1; i >= 0 && s[i] == ' '; i--) {}
        for (; i >= 0 && s[i] != ' '; i--, result++) {}
        return result;
    }
};