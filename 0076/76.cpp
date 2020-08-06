#include "./myheaders.h"

class Solution {
public:
    string minWindow(string s, string t)
    {
        int len1 = s.length(), len2 = t.length();
        if (len1 * len2 == 0)
            return "";
        // 构建哈希表
        unordered_map<char, int> hashs, hasht;
        for (int i = 0; i < len1; i++)
            hashs[s[i]]++;
        for (int i = 0; i < len2; i++)
            hasht[t[i]]++;

        for (int i = 0; i < 128; i++)
            if (hashs[i] < hasht[i]) return "";
        int start = 0, end = len1 - 1;
        // 找到第一个窗口
        for (; hashs[s[end]] > hasht[s[end]]; hashs[s[end]]--, end--) { }

        // 保存最短长度
        int len = end - start + 1;
        for (int i = 0, j = end; j < len1 && i < len1; i++) {
            // 收缩窗口
            for (; hashs[s[i]] > hasht[s[i]]; hashs[s[i]]--, i++) { }
            // 如果有更短
            if (j - i + 1 < len) {
                start = i;
                end = j;
                len = j - i + 1;
            }
            // 右边增加窗口
            for (j = j + 1; s[j] != s[i] && j < len1; hashs[s[j]]++, j++) { }
        }
        string result;
        for (int i = start; i <= end; i++) {
            result.push_back(s[i]);
        }
        return result;
    }
};