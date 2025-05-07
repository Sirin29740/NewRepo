package main

import "fmt"

func ans(a []int) int {
	m := len(a)
	current := a[0]
	maxsum := 0
	for i := 1; i < m; i++ {
		current = max(current+a[i], a[i])
		maxsum = max(maxsum, current)
	}
	return maxsum
}

func main() {
	m := []int{-2, 11, -4, 13, -5, 2}
	fmt.Println(ans(m))
}
