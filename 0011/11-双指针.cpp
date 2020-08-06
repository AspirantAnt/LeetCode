#include <vector>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxVoltage = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int tmpVoltage = ((j - i) * min(height[i], height[j]));
            maxVoltage = maxVoltage > tmpVoltage ? maxVoltage : tmpVoltage;
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxVoltage;
    }
};