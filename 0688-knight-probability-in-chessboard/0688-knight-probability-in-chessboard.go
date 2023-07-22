var(
    moves =[][]int{
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    }
)

func check(i, j, n int) bool {
    if i<0 || j< 0 || i>=n || j>=n {
        return false
    }
    return true
}

func knightProbability(n int, k int, row int, column int) float64 {
    dp0:=make([][]float64,n)
    for i:=0;i<n;i++{
        dp0[i]=make([]float64,n)
        for j:=0;j<n;j++{
            dp0[i][j]=1.0
        }
    }
    
    var dp1 [][]float64
    for move:=1;move<=k;move++{
        dp1 = make([][]float64, n)
        for i:=0;i<n;i++{
            dp1[i]=make([]float64, n)
            
            for j:=0;j<n;j++{
                for _,x:=range moves{
                    I,J := i+x[0], j+x[1]
                    if check(I, J, n) {
                        dp1[i][j] += 0.125*dp0[I][J]
                    }
                }
            }
        }
        dp0=dp1
    }
    return dp0[row][column]
}
