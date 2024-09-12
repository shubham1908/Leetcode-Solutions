class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> ad(26, 0);
        for(auto ch: allowed){
            ad[ch-'a']++;
        }
        int cnt = 0;
        for(auto word: words){
            bool f = true;
            for(auto ch: word){
                if(ad[ch-'a'] == 0){
                    f = false;
                    break;
                }
            }
            if(f) cnt++;
        }
        return cnt;
    }
};