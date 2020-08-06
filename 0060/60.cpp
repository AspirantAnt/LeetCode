#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<bool> used;
    string getPermutation(int n, int k) {
        used = vector<bool>(n, false);
        return getOne(n, k - 1);
    }

  private:
    string getOne(int n, int k) {
        if (n == 0) return "";
        if (k == 0) {
            string res;
            for (int i = 0; i < used.size(); i++) {
                if (!used[i]) {
                    char tmp = '0' + i + 1;
                    res = res + tmp;
                }
            }
            return res;
        }

        int x1 = jc(n - 1);
        int position = k / x1, i;

        for (i = 0; i < used.size(); i++) {
            if (!used[i]) {
                if (position == 0)
                    break;
                else
                    position--;
            }
        }
        char tmp = '0' + i + 1;
        used[i] = true;
        return tmp + getOne(n - 1, k % x1);
    }
    int jc(int k) {
        if (k == 1) return 1;
        return k * jc(k - 1);
    }
};
/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4 *
2 3 4 1
2 4 1 3
2 4 3 1
*/