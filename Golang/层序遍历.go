/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    ans := [][]int{}
    ps := []*TreeNode{root}
    for i:=0; len(ps)>0; i++ {
        ans = append(ans, []int{})
        q := []*TreeNode{}
        for j:=0; j<len(ps); j++ {
            node := ps[j]
            ans[i] = append(ans[i], node.Val)
            if node.Left != nil {
                q = append(q, node .Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        ps = q
    }
    return ans
}
