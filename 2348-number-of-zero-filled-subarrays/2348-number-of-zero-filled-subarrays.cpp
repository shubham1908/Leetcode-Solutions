class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, cnt = 0;
        for(auto num: nums){
            if(num == 0){
                cnt++;
            } else {
                ans += cnt* (cnt+1)/2;
                cnt = 0;
            }
        }
        ans += cnt* (cnt+1)/2;
        return ans;
    }
};