func combine(n int, k int) [][]int {
    ans := make([][]int, 0)
    temp := make([]int, 0)
    
    helper(0, n, k, &ans, &temp)
    return ans
}

func helper(i int, n int, k int, ans *[][]int, temp *[]int) {
    if len(*temp) == k {
        copyTemp := make([]int, k)
        copy(copyTemp, *temp)
        *ans = append(*ans, copyTemp)
        return
    }
    for x:= i+1; x<=n; x++ {
        *temp = append(*temp, x)
        helper(x, n, k, ans, temp)
        *temp = (*temp)[:len(*temp)-1]
    }
}