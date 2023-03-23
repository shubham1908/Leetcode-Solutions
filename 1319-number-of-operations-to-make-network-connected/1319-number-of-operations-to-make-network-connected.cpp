class Solution {
public:
    class DisjSet {
    public:
        int *par;
        int n;
        
        DisjSet(int n){
            this->n = n;
            par = new int[n];
            for(int i=0;i<n;i++){
                par[i] = i;
            }
        }
        
        int find(int x){
            if(par[x] != x){
                par[x] = find(par[x]);
            }
            return par[x];
        }
        
        int unionSet(int u, int v){
            int a = find(u);
            int b = find(v);
            if(a == b){
                return 1;
            }
            par[b] = a;
            return 0;
        }
        
        int numberOfComponets(){
            set<int> st;
            for(int i=0;i<n;i++){
                st.insert(find(i));
            }
            return st.size();
        }
    };
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraCables = 0;
        DisjSet disj(n);
        for(auto connection: connections){
            extraCables += disj.unionSet(connection[0], connection[1]);
        }
        int componentsCount = disj.numberOfComponets();
        if(extraCables < componentsCount - 1){
            return -1;
        }
        return componentsCount - 1;
    }
};