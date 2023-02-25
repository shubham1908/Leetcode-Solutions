class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x1 = 0, x2 = 0;
        for(auto e:arr1){
            x1 ^= e;
        }
        for(auto e: arr2){
            x2 ^= e;
        }
        return x1 &x2;
    }
};