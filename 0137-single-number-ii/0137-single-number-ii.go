func singleNumber(nums []int) int {
    var ans int32
    for i:=0;i<32;i++ {
        var sum int32
        for _, num:= range nums {
            if ((num >> i) & 1) == 1 {
                sum++
            }
        }
        sum %= 3
        ans |= (sum<<i)
    }
    return int(ans)
}