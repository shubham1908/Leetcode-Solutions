class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<long> div(k, 0);
        int m = *min_element(arr.begin(), arr.end());
        if(m < 0){
            m=-m;
        }
        for(auto e: arr){
            int x = (1L* m*k + e)%k;
            div[x]++;
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