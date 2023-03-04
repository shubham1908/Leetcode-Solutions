class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long ans = 0;
        int minRec = -1, maxRec = -1, last = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                minRec = nums[i] == minK ? i: minRec;
                maxRec = nums[i] == maxK ? i: maxRec;
                
                ans += max(0, min(minRec, maxRec) - last);
            } else {
                last = i;
                minRec = maxRec = -1;
            }
        }
        return ans;
    }
};