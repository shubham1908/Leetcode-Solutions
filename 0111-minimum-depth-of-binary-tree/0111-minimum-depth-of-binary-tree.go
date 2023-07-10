/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil{
        return 1
    }
    left, right := 1000000, 1000000
    if root.Left != nil {
        left = minDepth(root.Left)
    }
    if root.Right != nil {
        right = minDepth(root.Right)
    }

    return int(math.Min(float64(left), float64(right))) + 1
}