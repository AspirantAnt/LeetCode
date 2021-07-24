import java.util.*;

public class Solution {
    List<List<String>> result;
    int minLen;
    List<List<Integer>> path;
    // 给广搜做基础
    Map<String, Integer> word2index;
    boolean[] visited;
    int endWordIndex;
    List<String> index2word;

    public void dfs(String cur, List<String> nowList) {
        int nowLen = nowList.size();
        int restDiff = 0;
        for (int i = 0; i < cur.length(); i++) {
            if (cur.charAt(i) != index2word.get(endWordIndex - 1).charAt(i)) {
                restDiff++;
            }
        }
        if (nowLen < minLen && (nowLen + restDiff) <= minLen) {
            for (Integer index : path.get(word2index.get(cur))) {
                if (!visited[index]) {
                    nowList.add(index2word.get(index - 1));
                    visited[index] = true;
                    if (index == endWordIndex) {
                        if (nowList.size() < minLen) {
                            minLen = nowList.size();
                            result.clear();
                        }
                        result.add(new ArrayList<>(nowList));
                    } else {
                        dfs(index2word.get(index - 1), nowList);
                    }
                    visited[index] = false;
                    nowList.remove(nowList.size() - 1);
                }
            }
        }
    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        result = new ArrayList<>();
        if (!wordList.contains(endWord)) {
            return result;
        }
        this.index2word = wordList;
        endWordIndex = wordList.indexOf(endWord) + 1;
        int len = wordList.size();
        int lenWord = beginWord.length();
        minLen = len;
        // init path
        path = new ArrayList<>();
        for (int i = 0; i < len + 1; i++) {
            path.add(new LinkedList<>());
        }
        List<String> nowList = new ArrayList<>();
        nowList.add(beginWord);
        visited = new boolean[len + 1];
        visited[0] = true;
        word2index = new HashMap<>();
        word2index.put(beginWord, 0);

        // init arr[0]
        for (int i = 0; i < len; i++) {
            int cnt = 0;
            for (int n = 0; n < lenWord; n++) {
                if (beginWord.charAt(n) != wordList.get(i).charAt(n)) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                if (i + 1 == endWordIndex) {
                    nowList.add(endWord);
                    result.add(nowList);
                    minLen = 2;
                    return result;
                }
                path.get(0).add(i + 1);
                path.get(i + 1).add(0);
            }
            if (cnt != 0) {
                word2index.put(wordList.get(i), i + 1);
            }
        }

        // init rest path
        for (int i = 0; i < len; i++) {
            if (wordList.get(i).equals(beginWord)) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (wordList.get(j).equals(beginWord)) {
                    continue;
                }
                int cnt = 0;
                for (int n = 0; n < lenWord; n++) {
                    if (wordList.get(i).charAt(n) != wordList.get(j).charAt(n)) {
                        cnt++;
                    }
                }
                if (cnt == 1) {
                    path.get(i + 1).add(j + 1);
                    path.get(j + 1).add(i + 1);
                }
            }
        }
        dfs(beginWord, nowList);
        return result;
    }
}
