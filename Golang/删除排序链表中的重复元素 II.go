/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
     if head == nil {
        return nil
    }
   
    dummy := &ListNode{0,head} // 哨兵节点 
    p := dummy
    for p.Next!=nil && p.Next.Next!=nil{
        if p.Next.Val==p.Next.Next.Val{
            a:=p.Next.Val
            for p.Next!=nil &&p.Next.Val==a{
                p.Next=p.Next.Next
            }
        }else{
        p=p.Next
        }
    }
    return dummy.Next
}
