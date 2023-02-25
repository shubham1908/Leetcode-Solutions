class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int k=0;k<32;k++){
            int ones = 0;
            for(auto num: nums){
                ones += ((num>>k) & 1) == 1;
            }
            ans += ones * (nums.size() - ones);
        }
        return ans;
    }
};