class Solution {
    ArrayList<ArrayList<Integer>> adj;
    
    private int dfs(int node, int cnt, int visVal, int[] vis, int[] temp){
        vis[node] = visVal;
        temp[node] = cnt;
        // System.out.println("node "+ node);
        for(int nb: adj.get(node)){
            if(vis[nb] == -1){
                int x = dfs(nb, cnt+1, visVal, vis, temp);
                if(x != 0) {
                    return x;
                }
            } else {
                if(vis[nb] == visVal){
                    return cnt - temp[nb] + 1;
                } else {
                    return 0;
                }
                
            }
        }
        return 0;
    }
    
    public int longestCycle(int[] edges) {
        int n = edges.length;
        int[] temp = new int[n];
        int[] vis = new int[n];
        adj = new ArrayList<ArrayList<Integer>>();
        
        for(int i = 0;i<n;i++){
            vis[i] = -1;
            if(edges[i] == -1){
                adj.add(new ArrayList<Integer>());
            } else {
                adj.add(new ArrayList<Integer>(
                    Arrays.asList(edges[i])));
            }
        }
        // System.out.println(adj);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                int x = dfs(i, 0, i, vis, temp);
                if(x != 0){
                    ans = Math.max(ans, x);
                }
            }
            // System.out.println(temp[i]);
        }
        
        if(ans == 0){
            return -1;
        }
        return ans;
    }
}