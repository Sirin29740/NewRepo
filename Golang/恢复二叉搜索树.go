/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func recoverTree(root *TreeNode)  {
    var nums []int
    var inorder func(node *TreeNode)
    inorder = func(node *TreeNode){
        if node == nil {
        return
        }
        inorder(node.Left)
        nums = append(nums,node.Val)
        inorder(node.Right)
    }
    inorder(root)
    x,y := findxy(nums)
    recover(root,x,y,2)
}
func findxy(nums []int) (int,int){
    index1,index2 := -1,-1
    for i:=0;i<len(nums)-1;i++{
        if nums[i]>nums[i+1] {
            index2 = i+1
            if index1 == -1 {
                index1 = i
            }else {
                break
            }
        }
        
    }
    return nums[index1],nums[index2]
}
func recover(node *TreeNode,x int,y int,count int){
    if node == nil{
        return 
    }
    if node.Val == x || node.Val == y {
        if node.Val ==x {
            node.Val = y
        }else {
            node.Val = x
        }
        count--
    }
    if count == 0 {
        return
    }
    recover(node.Left,x,y,count)
    recover(node.Right,x,y,count)
}
