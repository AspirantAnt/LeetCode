#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;

        int len1 = haystack.length(), len2 = needle.length();
        if (len1 < len2) return -1;
        // if len2 == 1
        if (len2 == 1) {
            for (int i = 0; i < len1; i++) {
                if (haystack[i] == needle[0]) return i;
            }
            return -1;
        } else if (len2 > 1) {
            // define next array
            int *next = new int[len2];
            // init next array
            next[0] = -1;
            next[1] = 0;
            // get next array from 2 to len2
            for (int i = 2; i < len2; i++) {
                int n;
                // abcaabca
                for (n = 1; n < i; n++) {
                    int k1 = 0, k2 = n;
                    while (k2 < i && needle[k1] == needle[k2]) {
                        k1++;
                        k2++;
                    }
                    if (k2 == i) {
                        next[i] = k1;
                        break;
                    }
                }
                if (n == i) next[i] = 0;
            }
            // for(int i=0;i<len2;i++) {
            //     cout<<next[i]<<" ";
            // }
            // cout<<endl;
            // finish init next array

            int i, j;
            for (i = 0, j = 0; i < len1 && j < len2;) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else {
                    if (next[j] == -1) {
                        j = 0;
                        i++;
                    } else
                        j = next[j];
                }
            }
            if (j == len2)
                return i - len2;
            else
                return -1;
        }
        // finish if len2 > 1
        return -1;
    }
};