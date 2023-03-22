class Solution {
public: 
    class DisjSet {
    public:
        vector<pair<int, int>> parent;
        int n;
        
        DisjSet(int n){
            this->n = n;
            this->parent = vector<pair<int, int>>(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = {i, INT_MAX};
            }
        }
        
        pair<int, int> find(int u, int score){
            if(parent[u].first != u){
                parent[u] = find(parent[u].first, min(score, parent[u].second));
            }
            parent[u].second = min(score, parent[u].second);
            // cout<<u<<" "<<score<<'\n';
            return parent[u];
        }
        
        void unionSet(int u, int v, int score){
            // cout<<"insert "<<u<<" "<<v<<" "<<score<<"\n";
            pair<int, int> a = find(u, score);
            pair<int, int> b = find(v, score);
            if(a.second < b.second){
                parent[b.first] = a;
            } else {
                parent[a.first] = b;
            }
            // for(int i=1;i<=n;i++){
            //     cout<<"parent "<<parent[i].first<<" "<<parent[i].second<<
            //         '\n';
            // }
            // cout<<'\n';
        }
    };
    
    int minScore(int n, vector<vector<int>>& roads) {
        DisjSet disS(n);
        for(auto road: roads){
            disS.unionSet(road[0], road[1], road[2]);
        }
        return disS.find(1, INT_MAX).second;
    }
};