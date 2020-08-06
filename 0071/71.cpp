#include "../myheaders.h"

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        int len = path.length();
        if (len == 0 || path[0] != '/') return result;
        if (path[path.length() - 1] != '/') {
            path = path + '/';
            len++;
        }
        result = "/";
        bool flag = false;
        for (int i = 1; i < len; i++) {
            if (path[i] == '.') {
                if (i + 1 < len && path[i + 1] == '/') {
                    i++;
                    continue;
                } else if (i + 2 < len && path[i + 1] == '.' && path[i + 2] == '/') {
                    int l = result.length() - 2;
                    for (; l >= 0 && result[l] != '/'; l--) {}
                    if (l < 0) l = 0;
                    result = result.substr(0, l + 1);
                    i += 2;
                } else {
                    for (; i < len; i++) {
                        result = result + path[i];
                        if (path[i] == '/') break;
                    }
                }
            } else if (path[i] == '/') {
                if (!flag)
                    continue;
                else {
                    result = result + '/';
                    flag = false;
                }
            } else {
                result = result + path[i];
                flag = true;
            }
        }
        if (result[result.length() - 1] == '/' && result.length() != 1) result = result.substr(0, result.length() - 1);
        return result;
    }
};
//   /a/./b/../../c/