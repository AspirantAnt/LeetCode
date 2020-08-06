#include "./myheaders.h"

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        return Recursion(s1, s2);
    }
    bool Recursion(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        //防止超时，若s1中所有字符在s2中不都存在，说明s1无论怎么分割和s2无法匹配，直接返回false，大大优化效率
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2)
            return false;
        //i从1到s1.size-1，不能从下标0开始，至少分割1个字符出来，否则无法跳出循环
        for (int i = 1; i < s1.size(); i++)
        {
            //将s1分割成[0,i)[i,s1.size)对应s2匹配可能是[0,i)[i,s1.size)也可能是[s2.size-i,s2.size)[0,s2.size()-i)
            bool flag1 = Recursion(s1.substr(0, i), s2.substr(0, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
            bool flag2 = Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
            if (flag1 || flag2)
                return true;
        }
        return false;
    }
};