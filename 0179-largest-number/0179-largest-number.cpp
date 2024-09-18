class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int num1, int num2){
            string a = to_string(num1);
            string b = to_string(num2);
            return a+b> b+a;
        });
        if(nums[0] == 0){
            return "0";
        }
        string ans = "";
        for(auto num: nums){
            ans += to_string(num);
        }
        return ans;
    }
};