#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        // 初始化，开局只有一个0
        vector<int> result(1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> cp_result = result;
            for (auto num = cp_result.end() - 1; num >= cp_result.begin(); num--)
            {
                result.push_back(*num + pow(2, i - 1));
            }
        }
        return result;
    }
};