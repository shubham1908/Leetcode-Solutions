/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var (
    indexMap = make(map[*TreeNode]int)
    cnt = 0
)

func findIndexes(root *TreeNode) {
    if root == nil {
        return
    }
    indexMap[root] = cnt
    cnt++
    findIndexes(root.Left)
    cnt++
    findIndexes(root.Right)
}

func helper(root *TreeNode, dp [2][]int) (int, int){
    if root == nil {
        return 0, 0
    }
    ind := indexMap[root]
    if(dp[0][ind] != -1 && dp[1][ind] != -1){
        return dp[0][ind], dp[1][ind] 
    }
    leftP, leftNp := helper(root.Left, dp)
    rightP, rightNp := helper(root.Right, dp)
    
    dp[0][ind] = root.Val + leftNp + rightNp
    dp[1][ind] = (int)(math.Max(float64(leftP), float64(leftNp))) +  
    (int)(math.Max(float64(rightP), float64(rightNp)))
    return dp[0][ind], dp[1][ind]
}

func rob(root *TreeNode) int {
    cnt = 0
    findIndexes(root)
    cnt++;
    dp := [2][]int{make([]int, cnt), make([]int, cnt)}
    for i:=0;i<cnt;i++{
        dp[0][i], dp[1][i] = -1, -1
    }
    helper(root, dp)
    return (int)(math.Max(float64(dp[0][0]), float64(dp[1][0])))
}