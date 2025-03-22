func minCostClimbingStairs(cost []int) int {
    n:= len(cost)
    a, b := cost[0], cost[1]
    if n==2 {
        return min(a,b)
    }
    c:= 0
    for i:= 2;i< n;i++{
        c = min(a, b) + cost[i]
        a=b
        b=c
    }
    return min(a,c)

}
func min(a, b int) int{
    if a<b {
        return a
    }
    return b
}
