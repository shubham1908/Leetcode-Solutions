class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, 0);
        for(int i=0;i<words[0].size();i++){
            v[words[0][i]-'a']++;
        }
        for(auto s: words){
            vector<int> cnt(26, 0);
            for(auto c: s){
                cnt[c-'a']++;
            }
            for(int i=0;i<26;i++){
                v[i] = min(v[i], cnt[i]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            for(int j=0;j<v[i];j++){
                string x = "";
                x+=i+'a';
                ans.push_back(x);
            }
        }
        return ans;
    }
};