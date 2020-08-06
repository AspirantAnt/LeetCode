#include "./myheaders.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);
        vector<int> v1; // 保存下标
        v1.push_back(-1);
        int vlen = 0;
        int len = heights.size();
        int maxArea = 0;
        for (int i = 0; i < len; i++) {
            // cout<<vlen<<endl;
            if (v1[vlen] != -1 && heights[i] < heights[v1[vlen]]) {
                while (v1[vlen] != -1 && heights[i] < heights[v1[vlen]]) {
                    // cout<<"pop"<<endl;
                    int area = heights[v1[vlen]] * (i - v1[vlen - 1] - 1);
                    // cout<<"area: "<<area<<endl;
                    if (area > maxArea)
                        maxArea = area;
                    v1.pop_back();
                    vlen--;
                }
            }
            v1.push_back(i);
            vlen++;
            // cout<<"push"<<endl;
        }
        return maxArea;
    }
};