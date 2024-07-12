func maxProduct(words []string) int {
    arr := []int{}
    for _, e:= range words {
        x := 0
        for _, c:= range e {
            x |= 1<<(int(c- 'a'))
        }
        arr = append(arr, x)
    }
    ans := 0
    for i:=0; i<len(words);i++ {
        for j:=i+1; j<len(words);j++{
            if (arr[i] & arr[j]) == 0 {
                ans = max(ans, len(words[i]) * len(words[j]))
            }
        }
    }
    return ans
}