#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int result = 0;
        for (auto i = nums.begin(); i < nums.end();) {
            if (*i != val) {
                result++;
                i++;
            } else
                nums.erase(i);
        }
        return result;
    }
};