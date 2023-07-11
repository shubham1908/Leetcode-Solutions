/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
    var ans []int
    if k == 0 {
        ans = append(ans, target.Val)
        return ans
    }
    parMap := make(map[*TreeNode]*TreeNode)
    
    findPar(root, nil, parMap)
    distSubTree(target, k, &ans)
    distParTree(target, k, &ans, parMap)
    return ans
}

func findPar(root *TreeNode, par *TreeNode, parMap map[*TreeNode]*TreeNode) {
    if root != nil {
        if par != nil {
             parMap[root] = par
        }
        findPar(root.Left, root, parMap)
        findPar(root.Right, root, parMap)
    }
}

func distSubTree(root *TreeNode, k int, ans *[]int){
    if root != nil {
        
        if k == 0 {
            *ans = append(*ans, root.Val)
            return
        }
        distSubTree(root.Left, k-1, ans)
        distSubTree(root.Right, k-1, ans)
    }
} 

func distParTree(root *TreeNode, k int, ans *[]int, parMap map[*TreeNode]*TreeNode){
    if root != nil {
        par := parMap[root]
        if par == nil {
            return 
        }
        if k == 1 {
            *ans = append(*ans, par.Val)
            return
        }
        if par.Left != root {
            distSubTree(par.Left, k-2, ans)
        } else {
            distSubTree(par.Right, k-2, ans)
        }
        distParTree(par, k-1, ans, parMap)
    }
}