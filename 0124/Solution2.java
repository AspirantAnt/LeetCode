
// 本来还高兴说解决了难题，结果一看题解，自闭

public class Solution2 {
    int result = Integer.MIN_VALUE;

    public int getSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(getSum(root.left), 0);
        int right = Math.max(getSum(root.right), 0);
        result = Math.max(result, root.val + left + right);
        return root.val + Math.max(left, right);
    }

    public int maxPathSum(TreeNode root) {
        getSum(root);
        return result;
    }
}