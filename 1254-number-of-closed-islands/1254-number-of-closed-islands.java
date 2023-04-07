class Solution {
    int[][] move = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int n, m;
    
    private int check(int i, int j, int[][] grid){
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(grid[i][j] == 0){
            return 1;
        }
        return -1;
    }
    
    private boolean dfs(int i, int j, int[][] grid){
        grid[i][j] = 2;
        boolean f = false;
        for(int k = 0;k<4;k++){
            int I = i + move[k][0], J = j + move[k][1];
            int x = check(I, J, grid);
            if(x == 0){
                f = true;
            } else if(x == 1){
                f |= dfs(I, J, grid);
            }
        }
        return f;
    }
    
    public int closedIsland(int[][] grid) {
        int cnt = 0;
        n = grid.length;
        m = grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    if(!dfs(i, j, grid)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
}