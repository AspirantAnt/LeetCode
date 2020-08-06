#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // 使用一个map，然后index 为字符，value
        // 为下标，每有重复的，则对比当前长度，然后从重复的那个字符对应下标的下一个开始再重复即可
        unordered_map<char, int> record;
        int len = 0, result = 0, start_index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (record.find(s[i]) != record.end() && record[s[i]] >= start_index) {
                result = result > len ? result : len;
                len = i - record[s[i]];
                start_index = record[s[i]] + 1;
                record[s[i]] = i;
                continue;
            }
            len++;
            record[s[i]] = i;
        }
        result = result > len ? result : len;
        return result;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring("abba") << endl;
    return 0;
}