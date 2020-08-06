#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int len = strs.size();
        vector<vector<string>> result;
        unordered_map<string, int> words;
        int index = 0;
        for (int i = 0; i < len; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            // 找到是否已经有这种的组合
            if (words.count(tmp)) {
                result[words[tmp]].push_back(strs[i]);
            } else {
                result.push_back(vector<string>{strs[i]});
                words[tmp] = index++;
            }
        }
        return result;
    }
};