#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if ((digits[i] + 1) == 10) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                break;
            }
            if (i == 0) { digits.insert(digits.begin(), 1); }
        }
        return digits;
    }
};