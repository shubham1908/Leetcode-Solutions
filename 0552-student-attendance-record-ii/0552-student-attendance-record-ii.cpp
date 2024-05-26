class Solution {
public:
    int checkRecord(int n) {
        vector<vector<long>> dp(n, vector<long> (7, 0));
        dp[0][0] = dp[0][2] = dp[0][4] =  1;
        // last char as (A, P, L), and contains A or not contains A (NA)
        // 0 - A, 1 - P(A), 2 - P(NA), 3 - L1(A), 4 - L1(NA), 5 - L2(A), 6 - L2(NA)
        // which index of (i-1) should be added
        // 0 - 2, 4, 6
        // 1 - 0, 1, 3, 6
        // 2 - 2, 4, 6
        // 3 - 0, 1
        // 4 - 2
        // 5 - 3
        // 6 - 4
        vector<vector<int>> v{
            {2, 4, 6},
            {0, 1, 3, 5},
            {2, 4, 6},
            {0, 1},
            {2},
            {3},
            {4}
        };
        int MOD = 1e9+7;
        for(int i=1;i<n;i++){
            for(int j=0;j<7;j++){
                dp[i][j] =0;
                for(auto k: v[j]){
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
                }
                // cout<<dp[i][j]<<' ';
            }
            // cout<<'\n';
        }
        long ans = 0;
        for(int i=0;i<7;i++){
            ans = (ans + dp[n-1][i])%MOD;
        }
        return ans;
    }
};