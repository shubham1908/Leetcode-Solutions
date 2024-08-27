class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int> vis(n, 0);
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int u = t.second;
            if(vis[u]){
                continue;
            }
            vis[u] = 1;
            for(auto e: adj[u]){
                int v = e.first;
                if(t.first * e.second > prob[v]){
                    prob[v] = t.first * e.second;
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end_node];
    }
};