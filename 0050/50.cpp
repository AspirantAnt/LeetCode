#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    double myPow(double x, int n) {
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double cs = x;
        for (long long i = N; i; i = i / 2) {
            if (i % 2 == 1) { ans = ans * cs; }
            cs = cs * cs;
        }
        return ans;
    }
};
// cs *= cs 比 cs = cs * cs 要更耗时