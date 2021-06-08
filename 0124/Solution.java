public class Solution {
    // 返回int[2]的数组，第一个数 是能包括当前节点，第二个数是不包括当前节点
    public int[] possiblePath(TreeNode root) {
        if (root.left == null && root.right == null) {
            return new int[]{root.val, root.val};
        } else if (root.left == null) {
            int[] rightNode = possiblePath(root.right);
            return new int[]{Math.max(root.val, root.val + rightNode[0]), Math.max(rightNode[1], rightNode[0])};
        } else if (root.right == null) {
            int[] leftNode = possiblePath(root.left);
            return new int[]{Math.max(root.val, root.val + leftNode[0]), Math.max(leftNode[1], leftNode[0])};
        } else { // 同时有左右子树
            int[] leftNode = possiblePath(root.left);
            int[] rightNode = possiblePath(root.right);
            int list1 = Math.max(root.val, Math.max(root.val + leftNode[0], root.val + rightNode[0]));
            int list2 = Math.max(Math.max(leftNode[1], rightNode[1]), leftNode[0] + root.val + rightNode[0]);
            list2 = Math.max(list2, Math.max(root.val, Math.max(leftNode[0], rightNode[0])));
            return new int[]{list1, list2};
        }
    }

    public int maxPathSum(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root.val;
        } else if (root.left == null) {
            int[] rightNode = possiblePath(root.right);
            return Math.max(Math.max(root.val + rightNode[0], root.val), Math.max(rightNode[0], rightNode[1]));
        } else if (root.right == null) {
            int[] leftNode = possiblePath(root.left);
            return Math.max(Math.max(root.val + leftNode[0], root.val), Math.max(leftNode[0], leftNode[1]));
        } else {
            int[] leftNode = possiblePath(root.left);
            int[] rightNode = possiblePath(root.right);
            int result = Math.max(leftNode[1], rightNode[1]);
            result = Math.max(result, Math.max(leftNode[0], rightNode[0]));
            result = Math.max(result, Math.max(leftNode[0] + root.val, rightNode[0] + root.val));
            result = Math.max(result, leftNode[0] + root.val + rightNode[0]);
            result = Math.max(result, root.val);
            return result;
        }
    }
}
