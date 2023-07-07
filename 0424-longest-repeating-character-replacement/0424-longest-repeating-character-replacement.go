func characterReplacement(s string, k int) int {
    var ans int
    for i := 0; i< 26; i++ {
        ans = int(math.Max(float64(ans), float64(findMax(s, byte(int('A')+ i), k))))
    }
    return ans
}

func findMax(s string, c byte, k int) int {
    var l, r int
    var ans int
    // fmt.Println(s[r] == c)
    for r = 0; r < len(s); r++ {
        if s[r] == c || k > 0 {
            if s[r] != c {
                k--
            }
            // fmt.Println("r ", l, " ", r, " ", k)
            ans = int(math.Max(float64(ans), float64(r-l+1)))
            continue
        }
        // fmt.Println("l ", l, " ", r)
        for s[l] == c {
            l++
        }
        l++
        ans = int(math.Max(float64(ans), float64(r-l+1)))
    }
    return ans
}