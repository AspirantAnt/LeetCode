#include <iostream>
using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN)
                return -dividend;
            else
                return INT_MAX;
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = -1;

        long a = dividend;
        long b = divisor;
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        long result = f1(a, b);
        if (sign == -1 && result <= INT_MIN)
            return INT_MAX;
        else
            return sign * result;
    }
    long f1(long a, long b) {
        if (a < b) return 0;
        long cnt = 1;
        long tmp_b = b;
        while ((tmp_b + tmp_b) <= a) {
            cnt = cnt + cnt;
            tmp_b = tmp_b + tmp_b;
        }
        return cnt + f1(a - tmp_b, b);
    }
};