#include "../myheaders.h"

class Solution {
  public:
    string addBinary(string a, string b) {
        string result;
        int n = a.length(), m = b.length();
        bool add = false;
        int i, j;
        if (n > m)
            for (int k = 0; k < (n - m); k++) b = "0" + b;
        else if (n < m)
            for (int k = 0; k < (m - n); k++) a = "0" + a;
        int len = a.length();
        for (i = len - 1, j = len - 1; i >= 0 && j >= 0; i--, j--) {
            if (a[i] == '1' && b[j] == '1') {
                if (add)
                    result = "1" + result;
                else
                    result = "0" + result;
                add = true;
            } else if (a[i] == '1' || b[i] == '1') {
                if (add)
                    result = "0" + result;
                else
                    result = "1" + result;
            } else {
                if (add)
                    result = "1" + result;
                else
                    result = "0" + result;
                add = false;
            }
            if (i == 0 && j == 0 && add) result = "1" + result;
        }
        return result;
    }
};

int main() {
    string a = "11";
    string b = "1";
    cout << Solution().addBinary(a, b) << endl;
    return 0;
}