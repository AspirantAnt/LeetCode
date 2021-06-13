import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // 构建字典
        Set<String> dict = new HashSet<>(wordList);
        dict.remove(beginWord);
        int len = wordList.size();
        int wordLen = beginWord.length();

        // 排除特殊情况
        if (!dict.contains(endWord)) {
            return 0;
        }
        int step = 1;
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                char[] curArray = cur.toCharArray();
                for (int j = 0; j < wordLen; j++) {
                    char origin = curArray[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curArray[j] = c;
                        String newWord = String.valueOf(curArray);
                        //  如果当前字符存在
                        if (dict.contains(newWord)) {
                            // 如果是所需结果，返回结果并推出
                            if (newWord.equals(endWord)) {
                                return step + 1;
                            }
                            dict.remove(newWord);
                            queue.offer(newWord);
                        }
                    }
                    curArray[j] = origin;
                }
            }
            step++;
        }
        return 0;
    }
}