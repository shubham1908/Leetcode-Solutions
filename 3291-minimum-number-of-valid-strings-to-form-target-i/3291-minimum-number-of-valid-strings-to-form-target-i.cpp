class Solution {
public:
    class Trie{
    public:
        Trie* child[27] = {NULL};
    };
    Trie* root;
    
    void insert(string word){
        Trie* temp = root;
        for(auto ch: word){
            if(temp->child[ch-'a'] == NULL){
                temp->child[ch-'a'] = new Trie();
            }
            temp = temp->child[ch-'a'];
        }
    }
    
    int fun(int ind, string &target, vector<int>& dp){
        if(ind == target.length()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        Trie* node = root;
        int res = 1e9;
        for(int i=ind;i<target.length();i++){
            int cur = 0;
            if(node->child[target[i]-'a']){
                cur = 1+fun(i+1, target, dp);
            } else {
                if(i == ind) return 1e9;
                cur = 1 + fun(i, target, dp);
                res = min(res, cur);
                break;
            }
            res = min(res, cur);
            node = node->child[target[i]-'a'];
        }
        return dp[ind] = res;
        
    }
    
    
    int minValidStrings(vector<string>& words, string target) {
        root = new Trie();
        for(auto word:words){
            insert(word);
        }
        
        vector<int> dp(target.size(), -1);
        int ans =  fun(0, target, dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};