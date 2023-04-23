class Solution {
    public int MOD = (int)1e9+7;
    public int numberOfArrays(String s, int k) {
        int dp[] = new int[s.length() +1];
        dp[0] = 1;
        
        for(int i=1;i<=s.length();i++){
            long num = 0, pre = 0, d = 1;
            for(int j = i-1, l = 0;j>=0 && l<=9;j--, l++){
                num += (s.charAt(j) - '0')*d;
                d *= 10;
                if(num > k){
                    break;
                }
                if(num == pre){
                    continue;
                }
                pre = num;
                dp[i] = (dp[i] + dp[j])%MOD;
            }
        }
        return dp[s.length()];
    }
}