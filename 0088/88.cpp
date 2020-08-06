#include "./myheaders.h"

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int x = nums1.size() - 1; x >= m; x--)
        {
            nums1.pop_back();
        }
        int i = 0, j = 0;
        while (i < nums1.size() && j < n)
        {
            // 找到合适的位置
            while (nums1[i] < nums2[j] && i < nums1.size())
            {
                i++;
            }
            // 需要插到i的位置
            if (i >= nums1.size())
            {
                nums1.push_back(nums2[j]);
            }
            else
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
            }
            j++;
        }
        while (j < n)
        {
            nums1.push_back(nums2[j++]);
        }
    }
};