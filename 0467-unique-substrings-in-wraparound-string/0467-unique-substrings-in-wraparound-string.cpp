class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        int ans=0;
        vector<int>dp(n,0),fr(26,0);
        dp[n-1] =1;fr[s[n-1]-'a'] = 1;
        for(int i=n-2;i>=0;i--){
            if((s[i+1]-'a') == ((s[i]-'a'+1)%26)) {
                dp[i] = dp[i+1]+1;
            }
            else{
                dp[i]=1;
            }
            fr[s[i]-'a'] = max(fr[s[i]-'a'] , dp[i]);
        }
        for(auto x:fr){
            ans+=x;}
        
        return ans;
    }
};// abcdabc
//.      4321 3 21 

//zabab
//     32121
