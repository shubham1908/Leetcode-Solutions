class Solution {
public:
    vector<vector<int>> adj;
    
    long long dfs(int node, vector<int> &vis){
        long long cnt = 1;
        vis[node] = 1;
        for(auto child: adj[node]){
            if(vis[child] == 0){
                cnt += dfs(child, vis);
            }
        }
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        adj = vector<vector<int>> (n);
        
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        long long ans = 0, remainingNodes = n;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                int cnt = dfs(i, vis);
                ans += (cnt * (remainingNodes - cnt));
                remainingNodes -= cnt;
            }
        }
        
        return ans;
    }
};