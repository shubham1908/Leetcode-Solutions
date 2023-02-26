class Solution {
public:
    int n, m;
    
    int helper(string word1, string word2, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i == n){
            return m-j;
        }
        if(j == m){
            return n-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            dp[i][j] = helper(word1, word2, i+1, j+1, n, m, dp);
        } else {
            dp[i][j] = 1+ min(helper(word1, word2, i, j+1, n, m, dp),
                              min(helper(word1, word2, i+1, j, n, m, dp),
                                  helper(word1, word2, i+1, j+1, n, m, dp)));
        }
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        if(n == 0 || m == 0){
            return max(n, m);
        }
        vector<vector<int>> dp(n, vector<int> (m, -1));
        helper(word1, word2, 0, 0, n, m, dp);
        return dp[0][0];
    }
};