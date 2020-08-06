/*
执行用时: 960 ms, 在所有 C++ 提交中击败了21.23%的用户
内存消耗 :359.4 MB, 在所有 C++ 提交中击败了8.05%的用户
*/
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        // words 中元素的个数
        int nums = words.size();
        // 如果 words 元素个数为0 或者s 为空，则直接返回
        if (nums == 0 || s.length() == 0) return result;
        // words 中元素的长度
        int len = words[0].length();
        // words 组成的长度
        int cnt_len = nums * len;
        // 映射
        unordered_map<string, int> cnt;
        for (auto word : words)
            cnt[word]++;

        for (int i = 0; i < (s.length() - cnt_len + 1); i++) {
            string tmp = s.substr(i, cnt_len);
            unordered_map<string, int> ctmp;
            for (int n = 0; n < tmp.length(); n += len) {
                ctmp[tmp.substr(n, len)]++;
            }
            if (ctmp == cnt) result.push_back(i);
        }
        return result;
    }
};

int main() {
    vector<int> result;
    string str[] = {"foo", "bar"};
    vector<string> words(str, str + 2);
    string s = "barfoothefoobarman";
    result = Solution().findSubstring(s, words);
    cout << "Result: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}