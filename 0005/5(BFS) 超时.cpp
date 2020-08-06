#include <iostream>
#include <queue>
#include <string>
using namespace std;
// BFS Queue
class Solution {
public:
    string longestPalindrome(string s)
    {
        queue<string> q;
        q.push(s);
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            int len = tmp.length(), i;
            for (i = 0; i < len / 2; i++) {
                if (tmp[i] != tmp[len - i - 1]) {
                    // 入队
                    string tmp1 = tmp.substr(0, len - 1), tmp2 = tmp.substr(1, len);
                    q.push(tmp1);
                    q.push(tmp2);
                    break;
                }
            }
            if (i == len / 2)
                return tmp;
        }
        return "";
    }
};