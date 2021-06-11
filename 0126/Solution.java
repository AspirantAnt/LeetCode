import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> result = new ArrayList<>();
        // 快速判断字典
        Set<String> dict = new HashSet<>(wordList);
        // 特殊判断
        if (!dict.contains(endWord)) {
            return result;
        }
        dict.remove(beginWord);

        // 记录当前单词是在第几层遍历的时候得到的
        HashMap<String, Integer> steps = new HashMap<>();
        steps.put(beginWord, 0);

        Map<String, List<String>> from = new HashMap<>();
        int step = 1;
        boolean found = false;
        Queue<String> queue = new LinkedList<>();
        int len = wordList.size();
        int wordLen = beginWord.length();

        queue.offer(beginWord);

        // 开始广搜进行遍历
        while (!queue.isEmpty()) {
            int queueSize = queue.size();

            // 每层进行搜索
            for (int i = 0; i < queueSize; i++) {
                String cur = queue.poll();
                char[] curCharArray = cur.toCharArray();
                for (int j = 0; j < wordLen; j++) {
                    char originChar = curCharArray[j];
                    // 对当前字母进行替换，得到一个新的字母，看是否在wordList中
                    for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                        curCharArray[j] = newChar;
                        String newStringWord = String.valueOf(curCharArray);
                        // 如果当前step中的另一个word也可以转换成这个word,则需要加进去，不需要判断是否在dict中
                        if (steps.containsKey(newStringWord) && step == steps.get(newStringWord)) {
                            from.get(newStringWord).add(cur);
                        }
                        // 如果存在，则记录当前
                        if (dict.contains(newStringWord)) {
                            dict.remove(newStringWord);
                            queue.offer(newStringWord);

                            from.putIfAbsent(newStringWord, new ArrayList<>());
                            from.get(newStringWord).add(cur);

                            steps.put(newStringWord, step);

                            if (newStringWord.equals(endWord)) {
                                found = true;
                            }
                        }
                    }
                    curCharArray[j] = originChar;
                }
            }
            step++;
            if (found) {
                break;
            }
        }

        if (found) {
            Deque<String> path = new ArrayDeque<>();
            path.addFirst(endWord);
            dfs(from, path, beginWord, endWord, result);
        }
        return result;
    }

    public void dfs(Map<String, List<String>> from, Deque<String> nowPath, String beginWord, String curWord, List<List<String>> result) {
        if (curWord.equals(beginWord)) {
            result.add(new ArrayList<>(nowPath));
        } else {
            for (String s : from.get(curWord)) {
                nowPath.addFirst(s);
                dfs(from, nowPath, beginWord, s, result);
                nowPath.removeFirst();
            }
        }
    }
}
