var(
    ans []string
    ipments []int
)
func restoreIpAddresses(s string) []string {
    ipments = make([]int,4)
    ans = []string{}
    dfs(s,0,0)
    return ans
}
func dfs(s string,ipid int,start int){
    if ipid == 4 {
        if start == len(s){
            an := ""
            for i:=0;i<4;i++{
                an += strconv.Itoa(ipments[i])
                if i!=3{
                    an += "."
                }
            }
            ans = append(ans,an)
        }
        return
    }  
    if start == len(s){
        return
    }
    if s[start]=='0'{
        ipments[ipid] = 0
        dfs(s,ipid+1,start+1)
        return
    }
    add := 0
    for end := start; end<len(s);end++{
        add = 10*add + int(s[end]-'0')
        if add>0&&add<=0xFF {
            ipments[ipid]=add
            dfs(s,ipid+1,end+1)
        }else {
            break
        }
    }
}
