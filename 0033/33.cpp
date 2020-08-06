#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int xmin;
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        this->xmin = search(nums, 0, nums.size() - 1);
        int left = 0, right = nums.size() - 1;
        int mid = right / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            if (this->xmin > mid)
                return search(nums, target, mid + 1, this->xmin - 1);
            else if (this->xmin <= mid) {
                int tmp1 = search(nums, target, left, this->xmin - 1);
                int tmp2 = search(nums, target, mid + 1, right);
                if (tmp1 != -1 || tmp2 != -1) return tmp1 != -1 ? tmp1 : tmp2;
                return -1;
            }
        } else if (nums[mid] > target) {
            if (this->xmin < mid)
                return search(nums, target, this->xmin, mid - 1);
            else if (this->xmin >= mid) {
                int tmp1 = search(nums, target, left, mid - 1);
                int tmp2 = search(nums, target, this->xmin, right);
                if (tmp1 != -1 || tmp2 != -1) return tmp1 != -1 ? tmp1 : tmp2;
                return -1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target, int left, int right) {
        if (left > right)
            return -1;
        else if (left == right) {
            if (nums[left] == target)
                return left;
            else
                return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            return search(nums, target, mid + 1, right);
        } else
            return search(nums, target, left, mid - 1);
        return -1;
    }
    int search(vector<int> nums, int left, int right) {
        if (left > right) return -1;
        if (left == right) return left;
        int mid = (left + right) / 2;
        if (nums[mid] >= nums[left] && nums[mid] > nums[right]) {
            if (nums[mid] > nums[mid + 1])
                return mid + 1;
            else
                return search(nums, mid + 1, right);
        }
        if (nums[mid] <= nums[left] && nums[mid] < nums[right]) {
            if ((mid - 1) < left)
                return mid;
            else if (nums[mid - 1] > nums[mid])
                return mid;
            else
                return search(nums, left, right - 1);
        }
        return left;
    }
};