#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string tmp = countAndSay(n - 1);
        string result = "";
        for (int i = 0; i < tmp.length();) {
            int num = tmp[i] - '0';
            int cnt = 0;
            while ((tmp[i] - '0') == num && i <= tmp.length()) {
                cnt++;
                i++;
            }
            char count = cnt + '0';
            result = result + count + tmp[i - 1];
            ;
        }
        return result;
    }
};

int main() {
    string result = Solution().countAndSay(11);
    cout << result << endl;
    return 0;
}