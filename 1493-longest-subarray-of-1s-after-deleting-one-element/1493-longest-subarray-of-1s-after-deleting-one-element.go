func longestSubarray(nums []int) int {
    var i, j int
    var ans int
    var found bool
    for j < len(nums) {
        if nums[j] == 0 {
            if !found {
                found = true
            } else {
                for nums[i] != 0 {
                    i++
                }
                i++
            }
        }
        ans = int(math.Max(float64(ans), float64(j-i)))
        j++
    }
    return ans
}