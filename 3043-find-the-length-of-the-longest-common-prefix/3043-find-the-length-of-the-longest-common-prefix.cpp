class Solution {
public:
    class Node{
    public:
        Node* child[10];

        Node(): child{NULL}{}
    };
    
    class Trie {
    public:
        Node* root;
        
        Trie(){
            root = new Node();
        }
        
        void insert(int num){
            int d = log10(num);
            Node* node = root;
            for(int i=d;i>=0;i--){
                int x = num/pow(10, i);
                x = x%10;
                if(node->child[x] == NULL){
                    node->child[x] = new Node();
                }
                node = node->child[x];
            }
        }
    };
    
    int ans;
    void longestPrefix(Node *node1, Node *node2, int lvl){
        if(node1 == NULL || node2 == NULL){
            ans = max(ans, lvl);
            return;
        }
        for(int i=0;i<10;i++){
            longestPrefix(node1->child[i], node2->child[i], lvl+1);
        }
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie1;
        for(auto num: arr1){
            trie1.insert(num);
        }
        Trie trie2;
        for(auto num: arr2){
            trie2.insert(num);
        }
        ans = 0;
        longestPrefix(trie1.root, trie2.root, -1);
        return ans;
    }
};