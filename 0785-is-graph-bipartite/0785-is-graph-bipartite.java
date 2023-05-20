class Solution {
    public boolean dfs(int node, int[][] graph, int colour, int[] colours){
        colours[node] = colour;
        boolean f = true;
        for(int nei: graph[node]){
            if(colours[nei] == -1){
                f &= dfs(nei, graph, 1 - colour, colours);
            } else if(colours[nei] == colour){
                return false;
            }
        }
        return f;
    }
    
    public boolean isBipartite(int[][] graph) {
        int[] colours = new int[graph.length];
        for(int i=0;i<graph.length;i++){
            colours[i] = -1;
        }
        for(int i=0;i<graph.length;i++){
            if(colours[i] == -1 && !dfs(i, graph, 0, colours)){
                return false;
            }
        }
        return true;
    }
}