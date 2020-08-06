#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> result;
    string s;
    vector<string> words;
    int times = 0;
    vector<int> findSubstring(string s, vector<string> &words) {
        // 类似中心扩散思想
        // 先找到第一个单词的，然后两边扩散单词
        // 如果没有得到最后的答案，则找下一个中心
        if (words.size() == 0) return result;
        int len = words[0].length();
        string firstWord = words[0];
        words.erase(words.begin());
        this->words = words;
        this->s = s;
        for (int i = 0; i < s.length(); i++) {
            int j;
            for (j = 0; j < len; j++) {
                if (s[i + j] != firstWord[j]) break;
            }
            // 得到中心 i
            if (j != len) continue;
            // 如果只有一个word
            if (words.empty()) {
                result.push_back(i);
                continue;
            }
            // 开始扩散
            int left = i, right = i + len - 1;
            // 使用循环

            // 递归超出内存限制
            // 左边扩散
            this->spread(left, right, 1);
            // 右边扩散
            this->spread(left, right, 0);
        }
        return result;
    }

  private:
    void spread(int left, int right, bool fromLeft) {
        cout << "times: " << this->times << endl;
        this->times++;
        // cout<<left<<" "<<right<<" "<<fromLeft<<endl;
        // 开始扩散
        if (words.size() == 0) {
            // 判断left 是否已经有了
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == left) return;
            }
            result.push_back(left);
            return;
        }
        int n;
        int amount = words.size();
        int len = words[0].length();
        if (fromLeft) {
            left = left - len;
            if (left < 0) return;
            // 查找是否有这个words
            for (n = 0; n < amount; n++) {
                int i;
                for (i = 0; i < len; i++) {
                    if (words[n][i] != this->s[left + i]) break;
                }
                // 找到了合适的
                if (i == len) {
                    // words.erase(words.begin() + n);
                    break;
                }
            }
            // 没找到
            if (n == amount) return;
        } else {
            right = right + 1;
            if ((right + len - 1) >= this->s.length()) return;
            // 查找是否有这个words
            for (n = 0; n < amount; n++) {
                int i;
                for (i = 0; i < len; i++) {
                    if (words[n][i] != this->s[right + i]) break;
                }
                // 找到了合适的
                if (i == len) {
                    // words.erase(words.begin() + n);
                    right += len - 1;
                    break;
                }
            }
            // 没找到
            if (n == amount) return;
        }
        // 左边扩散
        string tmp = words[n];
        words.erase(words.begin() + n);
        if ((left - len) >= 0) this->spread(left, right, 1);
        // 右边扩散
        if ((right + len) < this->s.length()) this->spread(left, right, 0);
        words.push_back(tmp);
        return;
    }
};

int main() {
    vector<int> result;
    string str[] = {"mntbyktphdekchsdfqmbq", "zznsgammmykphdoipqruk", "hyssfppfmaqwrjbwjmnsl", "hkqbnvsbwkzguodmjwkub", "qsqhejswbmzqihcczorhv",
                    "xaljqomouvxelztjtwhdv", "dptikuqjpihyslwgderjd", "sozvqajhhgakrqrfltekk", "lszzhfpnxpfwfdbpacazl", "tavmlojstgisuefsvcloz",
                    "wjkdymsgldwxhlqlqjqsu", "dteopwnckmwmjkzavstec", "obzbizxyhuxjjsrjgexgo", "rwqwfivzjzjklfkbygbcz", "whngcwicqkhnercgrzuzc",
                    "frwihwkjvvugntweyqzcu", "rbiqhouaxxqroxvxrrags", "qmenrcfsezjlxzdsyizts", "cvukpcywlhboyjkzdyvji", "xkkpvstsyjfleilqbdxgj",
                    "ykrympsitwwtfpllnrfia", "daqgwzsmtfkbycitjzasc", "whqsfverejacbshshohjh", "oyitsewduvjpzzexnjkbh", "izmuyptvadrhqymmgqeqx",
                    "klqxordrveepedwlvmjkt", "qzltlwpxssusffjtrznow", "pgynstzdfskwqsfmcpixl", "vajtzbkzhfsvepnfawoiw"};
    vector<string> words(str, str + 29);
    result = Solution().findSubstring(
        "faoucbmnvdujheznbntaszqsxicczlagnqbrsnfptbycfapjnkjflbzilemkpotehwvblcsefqgnsxwgkhnvjpgutuhklcosylvjonqtfyiyyegimtfxilrdiantcdncpiofxgaegjce"
        "nkobguyqhsupsjkxnxbehrjgxjlespiiazjiviyeaswuegtrexxnogumrfskwcuwbfgynfdpzzmdfhwletbvbvjtcbfydbxhgdfuiilkhznpjmcnhdkjytecujbykafqdkmovaacbntk"
        "bwyjziuaeycyhfytfdllqybnabpbqlmujmdiwxkaxnzeuxzcdknvkqimtzojkcdtoiemhonedokanjcswpnihvvaxlljprdfzjrhzgnfwyfkjhchyssfppfmaqwrjbwjmnslwhqsfver"
        "ejacbshshohjhdaqgwzsmtfkbycitjzasccvukpcywlhboyjkzdyvjiwhngcwicqkhnercgrzuzcizmuyptvadrhqymmgqeqxrwqwfivzjzjklfkbygbczlszzhfpnxpfwfdbpacazlk"
        "lqxordrveepedwlvmjktfrwihwkjvvugntweyqzcupgynstzdfskwqsfmcpixlqmenrcfsezjlxzdsyiztswjkdymsgldwxhlqlqjqsudptikuqjpihyslwgderjdqsqhejswbmzqihc"
        "czorhvrbiqhouaxxqroxvxrragssozvqajhhgakrqrfltekkvajtzbkzhfsvepnfawoiwzznsgammmykphdoipqrukobzbizxyhuxjjsrjgexgomntbyktphdekchsdfqmbqxkkpvsts"
        "yjfleilqbdxgjhkqbnvsbwkzguodmjwkubxaljqomouvxelztjtwhdvqzltlwpxssusffjtrznowtavmlojstgisuefsvclozdteopwnckmwmjkzavstecoyitsewduvjpzzexnjkbhy"
        "krympsitwwtfpllnrfiaukzzjoivrrueisqxmysiulpmzazqfkqcwrbfilbzcxfmrwmdwelrsbfrdehjqznmsquabxcfuhtlfhqcmbvgeaxkggvxfilxyfabecgalbnrjdtxhodnqcxw"
        "isvpahmyomztqhveljvumotteyhuagskzozbxlclabgslcwylruzhnvnlejnkcxlswnpjrajsjefnadauxzbmwrzaamnclauhplrgocbxggkjmkdllgykzzkamzcxazhpkywycxxlfhu"
        "ttzfhhfrhedjqfnqfmxwzxuxztxmzgischzjrecajhjbmwrtlqqknmjpgg",
        words);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}