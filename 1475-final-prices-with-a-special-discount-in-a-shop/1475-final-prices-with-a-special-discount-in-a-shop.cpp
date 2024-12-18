class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            } 
            res[i] = prices[i];
            if(!st.empty()){
                res[i] -= st.top();
            }
            st.push(prices[i]);
        }
        return res;
    }
};