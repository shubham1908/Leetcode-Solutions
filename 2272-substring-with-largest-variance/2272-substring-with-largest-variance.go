func largestVariance(s string) int {
    var freq [26]int
    for _, c:= range s {
        freq[int(c-'a')]++
    }
    ans := 0
    
    for i:=0;i<26;i++ {
        for j:=0;j<26;j++ {
            if i == j ||freq[i] == 0 || freq[j] == 0 {
                continue
            } 
            cnt1 := 0
            cnt2 := 0
            rem := freq[j]
            for _, c := range s {
                if int(c -'a') == i {
                    cnt1++
                } else if int(c-'a') == j {
                    cnt2++
                    rem--
                }
                
                if cnt2 > 0 {
                    if ans < cnt1 - cnt2 {
                        ans = cnt1-cnt2
                    }
                }
                if cnt1 < cnt2 && rem > 0 {
                    cnt1 = 0
                    cnt2 = 0
                }
            }
        }
    }
    return ans
}