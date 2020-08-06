#include <iostream>
#include <string>
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
        // 先找到第一个words，然后前后补充cnt_len - len的范围
        string first_word = words[0];
        for (int i = 0; i < s.length(); i++) {
            int j;
            for (j = 0; j < first_word.length(); j++) {
                if (s[i + j] != first_word[j]) break;
            }
            // 找到了第一个数
            if (j == first_word.length()) {
                // 圈出范围 imin, imax
                int imin = i - cnt_len + len;
                while (imin < 0)
                    imin += len;
                int imax = i + cnt_len - 1;
                while (imax >= s.length())
                    imax -= len;
            }
        }
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