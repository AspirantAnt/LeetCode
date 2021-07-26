import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxPoints(int[][] points) {
        int len = points.length;
        if (len <= 2) {
            return len;
        }
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (result >= len - i || result > (len / 2)) {
                break;
            }
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int j = i + 1; j < len; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                } else {
                    if (dy < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    int gcbXY = gcb(Math.abs(dx), Math.abs(dy));
                    dx /= gcbXY;
                    dy /= gcbXY;
                }
                int key = dy + dx * 20001;
                map.put(key, map.getOrDefault(key, 1) + 1);
            }
            int tmpResult = 0;
            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                tmpResult = Math.max(tmpResult, entry.getValue());
            }
            result = Math.max(result, tmpResult);
        }
        return result;
    }

    private int gcb(int a, int b) {
        return b == 0 ? a : gcb(b, a % b);
    }
}