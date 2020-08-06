#include "../myheaders.h"

class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        vector<int> result;
        result.push_back(2);
        result.push_back(3);
        for (int i = 3; i < n; i++) {
            result.push_back(result[0] + result[1]);
            result.erase(result.begin());
        }
        return result[2];
    }
};

// 1 2 3 5 8 13 21 34 55
// 1-1-> 1 1
// 2-2-> 1 2
// 3-3-> 1 1, 1 2
// 4-5-> 1 1, 2 2
// 5-8-> 2 1, 3 2
// 6-13->3 1, 5 2
// 7-21->5 1, 8 2
// 8-34->8 1,13 2
// 9-55->13 1,21 2