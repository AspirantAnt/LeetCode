#include <iostream>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = 0;
            // 以1-n分别为节点
            for (int root = 1; root <= i; root++)
            {
                int left_num = root - 1;
                int right_num = i - root;
                sum = sum + dp[left_num] * dp[right_num];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};