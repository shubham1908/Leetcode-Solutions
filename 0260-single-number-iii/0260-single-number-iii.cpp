class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans = {0, 0};
        int x = 0, n = nums.size();
        for(int i=0;i<n;i++){
            x ^= nums[i];
        }
        int i = 0;
        for(i=0;i<32;i++){
            if((x>>i) & 1){
                break;
            }
        }
        for(int j=0;j<n;j++){
            if((nums[j]>>i)&1){
                ans[0] ^= nums[j];
            } else{
                ans[1] ^= nums[j];
            }
        }
        return ans;
    }
};