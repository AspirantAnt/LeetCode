import java.util.HashMap;
import java.util.Map;

class Solution_annotation {
    public int maxPoints(int[][] points) {
        // 表示有n个点
        int n = points.length;
        // 如果只有2个点以下，那么结果就是点的个数
        if (n <= 2) {
            return n;
        }
        // 结果
        int ret = 0;
        // 固定一个点，看其他点会不会在它的直线上
        for (int i = 0; i < n; i++) {
            // 如果已经的结果已经大于 当前点和其他点全部都在一条线上，那么不需要遍历了，break
            // n / 2，就是假设全部点都分布在两条线上，如果一条线的点数大于n/2.那么另一条线肯定不会比这个大
            if (ret >= n - i || ret > n / 2) {
                break;
            }
            // 构造一个斜率对应点数的哈希表
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int j = i + 1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    // 求最大公因数
                    int gcdXY = gcd(Math.abs(x), Math.abs(y));
                    // 得到最简分数
                    x /= gcdXY;
                    y /= gcdXY;
                }
                // 构造一个哈希值
                int key = y + x * 20001;
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
            int maxn = 0;
            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                int num = entry.getValue();
                // 点需要+1
                maxn = Math.max(maxn, num + 1);
            }
            ret = Math.max(ret, maxn);
        }
        // 返回结果
        return ret;
    }

    // 计算两个值的最大公因数
    public int gcd(int a, int b) {
        return b != 0 ? gcd(b, a % b) : a;
    }
}