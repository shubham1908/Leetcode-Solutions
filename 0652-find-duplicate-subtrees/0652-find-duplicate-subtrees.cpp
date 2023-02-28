/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string helper(TreeNode* root, map<string, pair<int, TreeNode*>> &mp, vector<TreeNode*> &ans){
        if(root == NULL){
            return "#";
        }
        string left = helper(root->left, mp, ans);
        string right = helper(root->right, mp, ans);
        string x = "";
        int y = root->val;
        if(y<0){
            x += "-";
            y = abs(y);
        }
        if(y == 0){
            x += "0";
        }
        while(y){
            x += y%10 + '0';
            y /= 10;
        }
        x = left + right + x;
        if(mp.find(x) == mp.end()){
            mp[x] = {1, root};
        } else {
            mp[x].first++;
        }
        return x;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, pair<int, TreeNode*>> mp;
        vector<TreeNode*> ans;
        helper(root, mp, ans);
        for(auto it: mp){
            if(it.second.first >= 2){
                ans.push_back(it.second.second);
            }
        }
        return ans;
    }
};