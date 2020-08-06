#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        bool isMinus = x < 0;
        if (x == 2147483647 || x == -2147483648)
            return 0;
        x = isMinus ? -x : x;
        int result = 0;
        while (x) {
            if ((!isMinus && (2147483647 - x % 10) / 10 < result) || (isMinus && (2147483648 - x % 10) / 10 < result))
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return isMinus ? -result : result;
    }
};

int main()
{
    cout << Solution().reverse(-2147483648) << endl;
    return 0;
}