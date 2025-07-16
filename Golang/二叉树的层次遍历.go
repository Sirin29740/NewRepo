package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func orderbylevel(root *TreeNode) {
	a := list.New()
	a.PushBack(root)
	for a.Len() > 0 {
		no := a.Remove(a.Front()).(*TreeNode)
		fmt.Print(no.Val)
		if no.Left != nil {
			a.PushBack(no.Left)
		}
		if no.Right != nil {
			a.PushBack(no.Right)
		}
	}
}
func main() {
	// 构造示例树
	//        1
	//      /   \
	//     2     3
	//    / \   /
	//   4   5 6
	root := &TreeNode{Val: 1,
		Left:  &TreeNode{Val: 2, Left: &TreeNode{Val: 4}, Right: &TreeNode{Val: 5}},
		Right: &TreeNode{Val: 3, Left: &TreeNode{Val: 6}},
	}

	fmt.Print("层序遍历: ")
	orderbylevel(root) // 输出: 1 2 3 4 5 6

}
