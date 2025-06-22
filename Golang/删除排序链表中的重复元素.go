/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    p := head
    if head==nil||head.Next==nil{return head}
    for p.Next!=nil {
        if (p.Val==p.Next.Val) {
            p.Next=p.Next.Next
        }else{
        p=p.Next
        }
    }
    return head
}
