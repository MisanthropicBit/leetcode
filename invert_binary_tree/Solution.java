/*
 Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
    This problem was inspired by this original tweet by Max Howell:
    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.*
 * */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    private static TreeNode invertSubtrees(TreeNode node) {
        if (node == null) {
            return node;
        }
        
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;

        node.left = invertSubtrees(node.left);
        node.right = invertSubtrees(node.right);

        if (node.left != null)
            System.out.println("Left : " + node.left.val);
        if (node.right != null)
            System.out.println("Right: " + node.right.val);
        
        return node;
    }
    
    public static TreeNode invertTree(TreeNode root) {
        return invertSubtrees(root);
    }

    public static void printTree(TreeNode node, int level) {
        if (node == null) {
            return;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        TreeNode a = new TreeNode(1, null, null);
        TreeNode b = new TreeNode(3, null, null);
        TreeNode c = new TreeNode(6, null, null);
        TreeNode d = new TreeNode(9, null, null);
        TreeNode e = new TreeNode(2, a, b);
        TreeNode f = new TreeNode(7, c, d);
        TreeNode root = new TreeNode(4, e, f);

        //printTree(root);
        root = invertTree(root);
        //printTree(root);

        System.out.println(root.val);
        System.out.println(root.left.val);
        System.out.println(root.right.val);
        System.out.println(root.left.left.val);
        System.out.println(root.left.right.val);
        System.out.println(root.right.left.val);
        System.out.println(root.right.right.val);

        //System.out.println("Root: " + root.val);
        //System.out.println("e: " + e.val);
        //System.out.println("f: " + f.val);
        //System.out.println("a: " + a.val);
        //System.out.println("b: " + b.val);
        //System.out.println("c: " + c.val);
        //System.out.println("d: " + d.val);
    }
}
