#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int tmp = x;
        int rev = 0;
        while (tmp) {
            rev = rev * 10 + tmp % 10;
            tmp /= 10;
        }
        if (rev == x)
            return true;
        return false;
    }
};

int main()
{
    cout << Solution().isPalindrome(-1) << endl;
    return 0;
}