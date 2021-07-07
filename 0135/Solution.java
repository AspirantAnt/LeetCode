class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return 1;
        }

        int[] leftToRight = new int[len];
        int[] rightToLeft = new int[len];
        leftToRight[0] = 1;
        rightToLeft[len - 1] = 1;
        boolean start = true;
        int result = 0;

        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                if (!start) {
                    leftToRight[i - 1] = 1;
                    start = true;
                }
                leftToRight[i] = leftToRight[i - 1] + 1;
            } else if (ratings[i] < ratings[i - 1]) {
                start = false;
            } else {
                leftToRight[i] = 1;
            }
        }
        start = true;
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (!start) {
                    rightToLeft[i + 1] = 1;
                    start = true;
                }
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            } else if (ratings[i] < ratings[i + 1]) {
                start = false;
            } else {
                rightToLeft[i] = 1;
            }
            result = result + Math.max(leftToRight[i], rightToLeft[i]);
        }
        result = result + Math.max(leftToRight[len - 1], rightToLeft[len - 1]);

        return result;

    }
}