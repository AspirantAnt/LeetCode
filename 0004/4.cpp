#include <iostream>
#include <vector>
using namespace std;

#define max(x, y) (x) > (y) ? float(x) : float(y)
#define min(x, y) (x) < (y) ? float(x) : float(y)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // 始终让nums1.size()<=nums2.size()
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size(), m = nums2.size();
        int imin = 0, imax = n;
        // 进行折半查找
        while (imin <= imax) {
            // 结束条件：已经把nums1 和nums2 进行对半分了，所以只需要判断i的位置对不对就行了
            int i = (imax + imin) / 2;
            int j = ((n + m + 1) / 2) - i;
            if (i < imax && nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            } else if (i > imin && nums1[i - 1] > nums2[j]) {
                imax = i - 1;
            } else {
                // 判断n+m 的奇偶，如果为偶的话那么就是(max(nums1[i], nums2[j])+max(nums1[i+1], nums2[j+1]))/2，如果为奇，那么结果就是max(nums1[i], nums2[j])
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return float(maxLeft);
                }

                int minRight = 0;
                if (i == n) {
                    minRight = nums2[j];
                } else if (j == m) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums2[j], nums1[i]);
                }

                return float(maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }
};