class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini = INT_MAX;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & 1) nums[i] *= 2;
            mini = min(mini, nums[i]);
            pq.push(nums[i]);
        }
        int ans = INT_MAX;
        while(true){
            int x = pq.top();
            pq.pop();
            ans = min(ans, x - mini);
            if(x & 1){
                break;
            }
            x /= 2;
            pq.push(x);
            mini = min(mini, x);
        }
        return ans;
    }
};