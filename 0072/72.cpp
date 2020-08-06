#include "./myheaders.h"

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 * len2 == 0)
            return len1 + len2;
        vector<vector<int>> op;
        // 初始化
        for (int i = 0; i <= len1; i++) {
            vector<int> row;
            for (int j = 0; j <= len2; j++) {
                if (i == 0)
                    row.push_back(j); // i为空时，只需要不断插入使得其等于word2
                else if (j == 0)
                    row.push_back(i); // 当j为空时，只需要不断删除使其等于word2
                else
                    row.push_back(0); // 当两个都不为空时，则不知道要怎么操作，置为0
            }
            op.push_back(row);
        }
        // 转移
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (word1[i] == word2[j])
                    op[i + 1][j + 1] = op[i][j];
                else
                    op[i + 1][j + 1] = 1 + min(min(op[i + 1][j], op[i][j]), op[i][j + 1]);
            }
        }
        return op[len1][len2];
    }
};