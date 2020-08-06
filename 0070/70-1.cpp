#include "../myheaders.h"
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        return climbStairs(n - 3) + climbStairs(n - 2) * 2;
    }
};