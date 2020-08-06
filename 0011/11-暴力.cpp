#include <vector>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxVoltage = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int tmp = (j - i) * min(height[j], height[i]);
                maxVoltage = tmp > maxVoltage ? tmp : maxVoltage;
            }
        }
        return maxVoltage;
    }
};