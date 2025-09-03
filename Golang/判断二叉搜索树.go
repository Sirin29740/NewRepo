/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    return helper(root,math.MinInt64,math.MaxInt64)
}
func helper(node *TreeNode, min int,max int) bool {
    if node == nil {
        return true
    }
    if min >= node.Val || max <= node.Val {
        return false
    }
    return helper(node.Left,min,node.Val)&&helper(node.Right,node.Val,max)
}
