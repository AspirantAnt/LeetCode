class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int len1 = matrix.size();
        if (len1 == 0)
            return false;
        int len2 = matrix[0].size();
        // 二分
        int maxLen = len1 * len2;
        int left = 0, right = maxLen - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            int x = mid / len2, y = mid % len2;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return false;
    }
};