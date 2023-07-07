func maxConsecutiveAnswers(answerKey string, k int) int {
    var l, r int
    var ans int
    k1 := k
    
    for r < len(answerKey) {
        if answerKey[r] == 'T' || k1 > 0{
            if answerKey[r] == 'F' {
                k1--
            }
            r++
            ans = int(math.Max(float64(ans), float64(r-l)))
            continue
        }
        for answerKey[l] == 'T' {
            l++
        }
        l++
        r++
        ans = int(math.Max(float64(ans), float64(r-l)))
    }
    k1, l, r = k, 0, 0
    for r < len(answerKey) {
        if answerKey[r] == 'F' || k1 > 0{
            if answerKey[r] == 'T' {
                k1--
            }
            r++
            ans = int(math.Max(float64(ans), float64(r-l)))
            continue
        }
        for answerKey[l] == 'F' {
            l++
        }
        l++
        r++
        ans = int(math.Max(float64(ans), float64(r-l)))
    }
    return ans
}