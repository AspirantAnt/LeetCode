#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return result;
        f1(digits, 0, "");
        return result;
    }

private:
    void f1(string digits, int index, string tmp)
    {
        if (index == digits.length()) {
            result.push_back(tmp);
            return;
        }
        if (digits[index] == '2') {
            f1(digits, index + 1, tmp + 'a');
            f1(digits, index + 1, tmp + 'b');
            f1(digits, index + 1, tmp + 'c');
        } else if (digits[index] == '3') {
            f1(digits, index + 1, tmp + 'd');
            f1(digits, index + 1, tmp + 'e');
            f1(digits, index + 1, tmp + 'f');

        } else if (digits[index] == '4') {
            f1(digits, index + 1, tmp + 'g');
            f1(digits, index + 1, tmp + 'h');
            f1(digits, index + 1, tmp + 'i');

        } else if (digits[index] == '5') {
            f1(digits, index + 1, tmp + 'g');
            f1(digits, index + 1, tmp + 'k');
            f1(digits, index + 1, tmp + 'l');

        } else if (digits[index] == '6') {
            f1(digits, index + 1, tmp + 'm');
            f1(digits, index + 1, tmp + 'n');
            f1(digits, index + 1, tmp + 'o');

        } else if (digits[index] == '7') {
            f1(digits, index + 1, tmp + 'p');
            f1(digits, index + 1, tmp + 'q');
            f1(digits, index + 1, tmp + 'r');
            f1(digits, index + 1, tmp + 's');

        } else if (digits[index] == '8') {
            f1(digits, index + 1, tmp + 't');
            f1(digits, index + 1, tmp + 'u');
            f1(digits, index + 1, tmp + 'v');

        } else if (digits[index] == '9') {
            f1(digits, index + 1, tmp + 'w');
            f1(digits, index + 1, tmp + 'x');
            f1(digits, index + 1, tmp + 'y');
            f1(digits, index + 1, tmp + 'z');
        }
    }
};

int main()
{
    vector<string> result = Solution().letterCombinations("23");
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << result[i] << endl;
    }
    return 0;
}