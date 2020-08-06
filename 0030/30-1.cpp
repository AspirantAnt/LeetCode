#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> result;
    long times;
    vector<int> findSubstring(string s, vector<string> &words) {
        this->times = 0;
        // 类似中心扩散思想
        // 先找到第一个单词的，然后两边扩散单词
        // 如果没有得到最后的答案，则找下一个中心
        if (words.size() == 0) return result;
        if (words[0].length() * words.size() > s.length()) return result;
        cout << s.length() << " " << words.size() << endl;
        if (words[0].length() * words.size() == s.length()) {
            while (!s.empty()) {
                int pos = s.find(words[0]);
                if (pos == s.npos) {
                    return result;
                } else {
                    s.erase(s.begin() + pos, s.begin() + pos + words[0].length());
                    words.erase(words.begin());
                }
            }
            if (words.empty()) result.push_back(0);
            return result;
        }
        int len = words[0].length();
        string firstWord = words[0];
        words.erase(words.begin());
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
            // 左边扩散
            this->spread(s, words, left, right, 1, 0);
            // 右边扩散
            this->spread(s, words, left, right, 0, 0);
        }
        return result;
    }

  private:
    void spread(string s, vector<string> words, int left, int right, bool fromLeft, bool limit) {
        this->times++;
        cout << "Times: " << this->times << "Limit: " << limit << endl;
        cout << left << " " << right << " " << fromLeft << endl;
        for (int i = 0; i < words.size(); i++)
            cout << words[i] << endl;
        cout << endl;
        // 开始扩散
        if (words.size() == 0) {
            // 判断left 是否已经有了
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == left) return;
            }
            result.push_back(left);
            return;
        }
        int amount = words.size();
        int len = words[0].length();
        if (fromLeft) {
            int tmp_left = left - len;
            if (tmp_left < 0) {
                if (!limit) this->spread(s, words, left, right, 0, 1);
                return;
            }
            // 查找是否有这个words
            int n;
            for (n = 0; n < amount; n++) {
                int i;
                for (i = 0; i < len; i++) {
                    if (words[n][i] != s[tmp_left + i]) break;
                }
                // 找到了合适的
                if (i == len) {
                    words.erase(words.begin() + n);
                    left = tmp_left;
                    break;
                }
            }
            // 没找到
            if (n == amount) {
                for (int i = 0; i < result.size(); i++) {
                    if (result[i] == left) return;
                }
                // 只能从另一个方向扩散
                if (!limit) this->spread(s, words, left, right, 0, 1);
                return;
            };
        } else {
            int tmp_right = right + len;
            if (tmp_right >= s.length()) {
                if (!limit) this->spread(s, words, left, right, 1, 1);
                return;
            }
            // 查找是否有这个words
            int n;
            for (n = 0; n < amount; n++) {
                int i;
                for (i = 0; i < len; i++) {
                    if (words[n][i] != s[tmp_right - len + i + 1]) break;
                }
                // 找到了合适的
                if (i == len) {
                    words.erase(words.begin() + n);
                    right = tmp_right;
                    break;
                }
            }
            // 没找到
            if (n == amount) {
                // 只能从另一个方向
                if (!limit) this->spread(s, words, left, right, 1, 1);
                return;
            };
        }
        // 因为找到了，所以两边都能扩散
        // 左边扩散
        if (limit)
            this->spread(s, words, left, right, fromLeft, limit);
        else if (!limit) {
            this->spread(s, words, left, right, fromLeft, limit);
        }
        // 右边扩散
        // this->spread(s, words, left, right, 0);
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
    cout << "Result: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}