class Solution {
    int[][] move = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int n, m;
    
    private int check(int i, int j, int[][] grid){
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(grid[i][j] == 1){
            return 1;
        }
        return -1;
    }
    
    private int dfs(int i, int j, int[][] grid){
        grid[i][j] = 2;
        int cnt = 1;
        for(int k = 0;k<4;k++){
            int I = i + move[k][0], J = j + move[k][1];
            int x = check(I, J, grid);
            if(x == 0){
                cnt = -1;
            } else if(x == 1){
                int y = dfs(I, J, grid);
                if(y != -1 && cnt != -1){
                    cnt+= y;
                } else {
                    cnt = -1;
                }
            }
        }
        return cnt;
    }
    
    public int numEnclaves(int[][] grid) {
        int cnt = 0;
        n = grid.length;
        m = grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int x = dfs(i, j, grid);
                    if(x != -1){
                        cnt+=x;
                    }
                }
            }
        }
        return cnt;
    }
}