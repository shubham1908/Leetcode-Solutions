class Solution {
    class Dsu{
        int[] par;
        
        Dsu(int n){
            this.par = new int[n+1];
            for(int i=1;i<=n;i++){
                par[i] = i;
            }
        }
        
        boolean union(int u, int v){
            int a = find(u);
            int b = find(v);
            if(a == b){
                return false;
            }
            par[b] = a;
            return true;
        }
        
        int find(int x){
            if(par[x] != x){
                return par[x] = find(par[x]);
            }
            return par[x];
        }
    }
    
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        Dsu aliceDsu = new Dsu(n);
        Dsu bobDsu = new Dsu(n);
        Arrays.sort(edges, new Comparator<int[]>(){
            @Override
          public int compare(int[] a, int[] b) {
            return b[0] - a[0];
          }
        });
        int ans = 0;
        for(int[] edge: edges){
            if(edge[0] == 3){
                boolean isAlice = aliceDsu.union(edge[1], edge[2]);
                boolean isBob = bobDsu.union(edge[1], edge[2]);
                if(!isAlice && !isBob){
                    ans++;
                }
            }
            else if(edge[0] == 1){
                if(!aliceDsu.union(edge[1], edge[2])){
                    ans++;
                }
            } else {
                if(!bobDsu.union(edge[1], edge[2])){
                    ans++;
                }
            }
        }
        Set<Integer> aliceSet = new LinkedHashSet<Integer>();
        Set<Integer> bobSet = new LinkedHashSet<Integer>();
        for(int i=1;i<=n;i++){
            aliceSet.add(aliceDsu.find(i));
            bobSet.add(bobDsu.find(i));
            if(aliceSet.size()>1 || bobSet.size()>1){
                return -1;
            }
        }
        return ans;
    }
}