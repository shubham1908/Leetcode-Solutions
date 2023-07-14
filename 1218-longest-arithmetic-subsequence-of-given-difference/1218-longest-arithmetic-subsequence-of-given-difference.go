func longestSubsequence(arr []int, difference int) int {
    lenMap := make(map[int]int)
    
    ans := 1
    for _, e:= range arr {
        x:= 1
        if d, ok := lenMap[e-difference]; ok {
            x = d + 1 
        }
        lenMap[e] = x
        if ans < lenMap[e] {
            ans = lenMap[e]
        }
    }
    return ans
}