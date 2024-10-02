class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int cnt = 1;
        vector<int> ans(arr.size());
        for(auto x: mp){
            for(int i=0;i<x.second.size();i++){
                ans[x.second[i]] = cnt;
            }
            cnt++;
        }
        return ans;
    }
};