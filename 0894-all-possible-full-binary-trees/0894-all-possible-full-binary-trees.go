/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var(
    mp = make(map[int][]*TreeNode)
)
func allPossibleFBT(n int) []*TreeNode {
    if (n % 2) == 0 {
        fmt.Println(n, 0)
        return []*TreeNode{}
    }
    if n == 1 {
        return []*TreeNode{{}}
    }
    if x, ok := mp[n]; ok {
        return x
    }
    res := make([]*TreeNode, 0)
    
    for i:=1;i<n;i+=2 {
        left := allPossibleFBT(i)
        right := allPossibleFBT(n-i-1)
        
        for _, l := range left {
            for _, r:= range right {
                res = append(res, &TreeNode{
                    Val: 0,
                    Left: l,
                    Right: r,
                })
            }
        }
    }
    mp[n] = res
    return res
}