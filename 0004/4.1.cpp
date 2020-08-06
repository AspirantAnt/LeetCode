#include <iostream>
#include <vector>
using namespace std;

#define max(x, y) (x) > (y) ? (x) : (y)
#define min(x, y) (x) < (y) ? (x) : (y)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        // To ensure the nums1 is the shorter one.
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int imin = 0, imax = m;

        // 二分找到合适的位置
        while (imin <= imax) {
            int i = (imax + imin) / 2;
            // If j=((n+m+1)/2)-i, the maxleft should be cal. first and return.
            int j = ((n + m) / 2) - i;
            if (i > imin && nums1[i - 1] > nums2[j]) {
                imax = i - 1;
            } else if (i < imax && nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            } else { // have the right i

                // get min right number
                int minright;
                if (i == m) {
                    minright = nums2[j];
                } else if (j == n) {
                    minright = nums1[i];
                } else {
                    minright = min(nums1[i], nums2[j]);
                }
                // 要先提交，不然还会计算其他的
                if ((n + m) % 2)
                    return minright;

                // get max left number
                int maxleft;
                if (i == 0) {
                    maxleft = nums2[j - 1];
                } else if (j == 0) {
                    maxleft = nums1[i - 1];
                } else {
                    maxleft = max(nums1[i - 1], nums2[j - 1]);
                }
                return float(maxleft + minright) / 2.0;
            }
        }
    }
};
