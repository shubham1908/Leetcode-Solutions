class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>v(n);
        int cnt = 1;
        v[0] = cnt;
        for(int i = 1;i < n; i++){
            if((nums[i]&1) != (nums[i-1]&1)){
                v[i] = cnt;
            }
            else {
                
                cnt++;
                v[i]=cnt;
            }
        }
        vector<bool>ans;
        for(auto x:queries){
            ans.push_back(v[x[0]]==v[x[1]]);
        }
        return ans;
    }
};