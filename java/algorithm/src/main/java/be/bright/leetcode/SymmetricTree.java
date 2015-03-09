package be.bright.leetcode;

import be.bright.tools.StdOut;

import java.util.Stack;

/**
 * Created by barroco on 10/25/14.
 */
public class SymmetricTree {
    public static void main(String[] args) {
        StdOut.println("test");
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public boolean isSymmetric(TreeNode root) {
        return root == null || isSymmetric(root.left, root.right);
    }

    public boolean isSymmetricIteratively(TreeNode root) {
        if (root == null) {
            return true;
        }
        Stack<TreeNode> lstk, rstk;
        TreeNode lnode, rnode;
        lstk = new Stack<TreeNode>();
        rstk = new Stack<TreeNode>();
        lstk.push(root.left);
        rstk.push(root.right);
        while (!lstk.isEmpty() && !rstk.isEmpty()) {
            lnode = lstk.pop();
            rnode = rstk.pop();
            if (lnode == null && rnode != null)
                return false;
            if (lnode != null) {
                if(rnode == null || lnode.val != rnode.val)
                    return false;
                lstk.push(lnode.right);
                lstk.push(lnode.left);
                rstk.push(rnode.left);
                rstk.push(rnode.right);
            }
        }
        return lstk.isEmpty() && rstk.isEmpty();
    }

    public boolean isSymmetric(TreeNode r1, TreeNode r2) {
        if (r1 == null || r2 ==null) {
            return r2 == r1;
        }

        return r1.val == r2.val && isSymmetric(r1.left, r2.right) && isSymmetric(r1.right, r2.left);
    }


}
