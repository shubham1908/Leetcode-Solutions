class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(auto c: s){
            if(c == '['){
                cnt++;
            } else {
                if(cnt != 0){
                    cnt--;
                }
            }
        }
        return (cnt +1)/2;
    }
};