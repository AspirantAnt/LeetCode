class Solution {

    int result = 0;

    public void getLeafNum(int num, TreeNode root) {
        if(root.left == null && root.right == null) {
            result += num * 10 + root.val;
            return;
        }
        if(root.left != null) {
            getLeafNum(num * 10 + root.val, root.left);
        }
        if(root.right != null) {
            getLeafNum(num * 10 + root.val, root.right);
        }
    }

    public int sumNumbers(TreeNode root) {
        if(root.left == null && root.right == null ) {
            return root.val;
        }
        if (root.left != null) {
            getLeafNum(root.val, root.left);
        }
        if (root.right != null) {
            getLeafNum(root.val, root.right);
        }
        return result;
    }
}