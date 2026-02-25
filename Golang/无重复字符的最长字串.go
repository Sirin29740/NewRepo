func lengthOfLongestSubstring(s string) int {
    m := make(map[byte]int)
    l,r := 0,-1
    for i:=0;i < len(s); i++ {
        if i!=0 {
            delete(m,s[i-1])
        }
        for r < len(s)-1 && m[s[r+1]]==0 {
            m[s[r+1]]++
            r++
            
        }
        l = max(r-i+1,l)
    }
    return l
}
func max(a,b int) int{
    if a>b {
        return a
    }
    
    return b
}
