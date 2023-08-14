class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0, k = nums.size()-1;i<nums.size()/2;i++, k--){
            ans = max(ans, nums[i] + nums[k]);
        }
        return ans;
    }
};