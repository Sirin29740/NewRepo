package main

import "fmt"

func res(matris [][]int) int {
	m := len(matris)
	n := len(matris[0])
	res := make([][]int, m)
	for i := 0; i < m; i++ {
		res[i] = make([]int, n)
	}
	res[0][0] = matris[0][0]
	for i := 1; i < m; i++ {
		res[i][0] = matris[i][0] + res[i-1][0]
	}
	for i := 1; i < n; i++ {
		res[0][i] = matris[0][i] + res[0][i-1]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			res[i][j] = min(res[i][j-1], res[i-1][j]) + matris[i][j]
		}
	}
	return res[m-1][n-1]
}
func main() {
	var matris = [][]int{
		{1, 3, 5, 9},
		{8, 1, 3, 4},
		{5, 0, 6, 1},
		{8, 8, 4, 0},
	}
	fmt.Println(res(matris))
}
