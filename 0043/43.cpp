#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1.length() == 0 || num2.length() == 0) return "";
        int len1 = num1.length(), len2 = num2.length();
        if (num1[0] == '0' || num2[0] == '0') return "0";
        // 从左到右
        string result;
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int tmp1 = num1[i] - '0', tmp2 = num2[j] - '0';
                cout << "num: " << tmp1 << " " << tmp2 << endl;
                // 计算位数
                int index = (len1 + len2 - 2) - (i + j);
                cout << "index: " << index << endl;
                int len = result.length();
                char add_char = '0' + (tmp1 * tmp2) % 10;
                int add_int1 = (tmp1 * tmp2) % 10;
                int add_int2 = (tmp1 * tmp2) / 10;
                if (index == len) {
                    result = result + add_char;
                } else {
                    int now = result[index] - '0';
                    add_int1 = now + add_int1;
                    result[index] = '0' + add_int1 % 10;
                    add_int2 += add_int1 / 10;
                }
                add_char = '0' + add_int2;
                cout << add_int2 << endl;
                if (index >= len - 1)
                    result = result + add_char;
                else
                    result[index + 1] += add_int2;
                cout << "result: " << result << "\n" << endl;
            }
        }
        string ans;
        for (int n = 0; n < result.length(); n++) { ans = result[n] + ans; }
        if (ans[0] == '0') ans = ans.substr(1, ans.length() - 1);
        return ans;
    }
};

int main() {
    cout << Solution().multiply("123", "456");
    return 0;
}