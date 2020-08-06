#include "../myheaders.h"

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        int len = words.size(), position = 0;
        vector<int> space;
        if (len == 0) return result;
        result.push_back(words[0]);
        for (int i = 1; i < len; i++) {
            // 直接加入
            if (words[i].length() + result[position].length() + 1 <= maxWidth) {
                space.push_back(result[position].length());
                result[position] = result[position] + " " + words[i];
            }
            // 超过，加到下一排
            else {
                // 需要加空格
                // 如果只有一个单词，则直接后面加空格即可
                if (space.empty()) {
                    int nowLen = result[position].length();
                    for (; nowLen < maxWidth; nowLen++) { result[position] = result[position] + " "; }
                }
                // 有2个或者2个以上的单词
                else {
                    int spaceNum = space.size();
                    // 从后往前加空格
                    for (int spacePosition = spaceNum - 1; spacePosition >= 0; spacePosition--, spaceNum--) {
                        int nowLen = result[position].length();
                        int addNum = (maxWidth - nowLen) / spaceNum;
                        // 加入空格
                        for (int i = 0; i < addNum; i++) { result[position].insert(result[position].begin() + space[spacePosition], ' '); }
                    }
                }
                space.clear();
                // 加到下一排
                result.push_back(words[i]);
                position++;
            }
        }
        int nowLen = result[position].length();
        for (; nowLen < maxWidth; nowLen++) { result[position] = result[position] + " "; }
        return result;
    }
};