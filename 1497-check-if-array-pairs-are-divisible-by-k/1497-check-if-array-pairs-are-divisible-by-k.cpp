class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<long> div(k, 0);

        for(auto e: arr){
            div[(e%k+k)%k]++;
        }
        for(int i=1;i<k;i++){
            if(div[i] != div[k-i]){
                return false;
            }
        }
        if(div[0]%2){
            return false;
        }
        return true;
    }
};