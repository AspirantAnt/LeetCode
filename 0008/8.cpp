#include <iostream>
#include <string>
using namespace std;
#define INT32_MIN (-2147483647 - 1)
#define INT32_MAX (2147483647)

class Solution {
public:
    int myAtoi(string str)
    {

        // step 1: delete head space
        int index;
        while (str[0] == ' ')
            str.erase(0, 1);

        if (str.empty())
            return 0;

        // get symbol
        int isMinus = 1;
        if (str[0] == '+' || str[0] == '-') {
            isMinus = str[0] == '+' ? 1 : -1;
            str.erase(0, 1);
        }

        // get number
        int result = 0;
        int len = 0;
        while (str[0] >= '0' && str[0] <= '9' && !str.empty()) {
            len++;
            if (len > 10) {
                return isMinus ? INT32_MIN : INT32_MAX;
            }
            int tmp = str[0] - '0';
            // out of the range of int32
            if ((INT32_MAX - tmp) / 10.0 < isMinus * result) {
                return INT32_MAX;
            } else if (isMinus * result < (INT32_MIN + tmp) / 10.0) {
                return INT32_MIN;
            }
            result = result * 10 + tmp;
            str.erase(0, 1);
        }
        return result * isMinus;
    }
};

int main()
{
    cout << Solution().myAtoi("  -321") << endl;
    return 0;
}