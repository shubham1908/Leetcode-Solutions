/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    long[][] level;
    Solution() {
        level = new long[3001][2];
        for(int i=0;i<3001;i++){
            level[i][0] = -30000;
            level[i][1] = -30000;
        }
    }
    
    void helper(TreeNode root, int lvl, long cnt){
        if(root == null){
            return;
        }
        helper(root.left, lvl+1, cnt * 2);
        if(level[lvl][0] == -30000){
            level[lvl][0] = cnt;
        }
        level[lvl][1] = Math.max(level[lvl][1], cnt);
        helper(root.right, lvl+1, cnt*2 +1);
    }
    
    
    public int widthOfBinaryTree(TreeNode root) {
        helper(root, 0, 1);
        int ans = 0;
        for(int i=0;i<3001;i++){
            ans = (int)Math.max(ans, level[i][1] - level[i][0]+1);
        }
        return ans;
    }
}