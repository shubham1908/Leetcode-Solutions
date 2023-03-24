class Solution {
public:
    vector<vector<pair<int, int>>> adj; 
    
    int dfs(int node, int par){
        int cnt = 0;
        for(auto child: adj[node]){
            if(child.first != par){
                cnt += child.second + dfs(child.first, node);
            }
        }
        return cnt;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj = vector<vector<pair<int, int>>>(n);
        for(auto connection: connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        
        return dfs(0, -1);
    }
};