func minSubArrayLen(target int, nums []int) int {
    var l, r int
    var ans, curSum int
    ans = len(nums)+1
    for r = 0;r<len(nums);r++ {
        curSum += nums[r];
        for curSum >= target {
            ans = int(math.Min(float64(ans), float64(r-l+1)))
            curSum -= nums[l]
            l++
        }
    }
    if ans == len(nums)+1 {
        return 0
    }
    return ans
}