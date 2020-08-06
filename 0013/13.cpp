#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int len = s.length();
        int result = 0;
        int maxNum = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == 'M') {
                if (1000 >= maxNum) {
                    result += 1000;
                    maxNum = 1000;
                } else {
                    result -= 1000;
                }
            } else if (s[i] == 'D') {
                if (500 >= maxNum) {
                    result += 500;
                    maxNum = 500;
                } else {
                    result -= 500;
                }
            } else if (s[i] == 'C') {
                if (100 >= maxNum) {
                    result += 100;
                    maxNum = 100;
                } else {
                    result -= 100;
                }
            } else if (s[i] == 'L') {
                if (50 >= maxNum) {
                    result += 50;
                    maxNum = 50;
                } else {
                    result -= 50;
                }
            } else if (s[i] == 'X') {
                if (10 >= maxNum) {
                    result += 10;
                    maxNum = 10;
                } else {
                    result -= 10;
                }
            } else if (s[i] == 'V') {
                if (5 >= maxNum) {
                    result += 5;
                    maxNum = 5;
                } else {
                    result -= 5;
                }
            } else if (s[i] == 'I') {
                if (1 >= maxNum) {
                    result += 1;
                    maxNum = 1;
                } else {
                    result -= 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    cout << Solution().romanToInt("III") << endl;
    return 0;
}