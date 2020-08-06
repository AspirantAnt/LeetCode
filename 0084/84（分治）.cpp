#include "./myheaders.h"

class Solution {
public:
    int calcArea(vector<int> heights, int start, int end)
    {
        if (start > end)
            return 0;
        int minIndex = start;
        for (int i = start; i <= end; i++) {
            if (heights[minIndex] > heights[i])
                minIndex = i;
        }
        int area = (end - start + 1) * heights[minIndex];
        return max(area, max(calcArea(heights, start, minIndex - 1), calcArea(heights, minIndex + 1, end)));
    }
    int largestRectangleArea(vector<int>& heights)
    {
        return calcArea(heights, 0, heights.size() - 1);
    }
};