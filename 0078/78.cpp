#include "./myheaders.h"

class Solution {
private:
    string toBin(int n)
    {
        string result = "";
        while (n) {
            result = char((n % 2) + '0') + result;
            n /= 2;
        }
        return result;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if (len == 0) return result;

        for (int i = 0; i < pow(2, len); i++) {
            string bin = toBin(i);
            int step = len - bin.length();
            vector<int> tmp;
            for (int j = 0; j < bin.length(); j++) {
                if (bin[j] == '1') tmp.push_back(nums[j + step]);
            }
            result.push_back(tmp);
        }

        return result;
    }
};