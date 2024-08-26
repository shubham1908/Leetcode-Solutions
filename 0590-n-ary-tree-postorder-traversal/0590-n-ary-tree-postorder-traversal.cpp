/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void fun(Node *root, vector<int> &res){
        if(root == NULL){
            return;
        }
        for(auto ch: root->children){
            fun(ch, res);
        }
        res.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        fun(root, res);
        return res;
    }
};