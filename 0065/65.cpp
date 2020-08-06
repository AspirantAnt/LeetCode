#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isNumber(string s) {
        try {
            cout << double(s) << endl;
            return true;
        } catch (const std::exception &e) { return false; }
    }
};