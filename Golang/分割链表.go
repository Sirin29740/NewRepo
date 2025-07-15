/**
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    small := &ListNode{}
    smallhead := small
    large := &ListNode{}
    largehead := large
    for head != nil {
        if head.Val < x {
            small.Next = head
            small = small.Next
        }else {
            large.Next = head
            large = large.Next
        }
        head = head.Next
    }
    large.Next = nil
    small.Next = largehead.Next
    return smallhead.Next
}
