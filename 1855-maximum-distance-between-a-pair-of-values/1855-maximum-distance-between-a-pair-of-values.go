func maxDistance(nums1 []int, nums2 []int) int {
    i, j := 0, 0
    ans := 0
    for j < len(nums2) && i<len(nums1) {
        for j < len(nums2) && nums1[i] <= nums2[j] {
            j++
        }
        if ans < (j-i-1) {
            ans = j-i-1
        }
        i++
    }
    return ans
}