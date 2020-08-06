#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStart = -1, jStart = -1, m = s.length(), n = p.length();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                iStart = i;
                jStart = j++;
            } else if (iStart >= 0) {
                i = ++iStart;
                j = jStart + 1;
            } else
                return false;
        }
        while (j < n && p[j] == '*') ++j;
        return j == n;
    }
};