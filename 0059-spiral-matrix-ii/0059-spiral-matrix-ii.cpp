class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int x = 1;
        int top = 0, left = 0, right = n-1, bottom = n-1;
        int row = 0, col = 0;
        while(x <= n *n){
            for(col = left; col<=right && x<= n*n;col++){
                ans[top][col] = x;
                x++;
            }
            top++;
            for(row = top; row<=bottom && x<= n*n;row++){
                ans[row][right] = x;
                x++;
            }
            right--;
            for(col = right; col>=left && x<= n*n;col--){
                ans[bottom][col] = x;
                x++;
            }
            bottom--;
            for(row = bottom; row>=top && x <= n*n; row--){
                ans[row][left] = x;
                x++;
            }
            left++;
        }
        return ans;
    }
};