func topKFrequent(nums []int, k int) []int {
    freq := map[int]int{}
    
    for _, num := range nums {
        freq[num] = freq[num] + 1
    }
    n := len(nums)
    bucket := make([][]int, n+1)
    for key, val := range freq {
        bucket[val] = append(bucket[val], key)
    }

    var res []int
    for i := n; i >=0 && k>0;i-- {
        for _, key := range bucket[i]{
            res = append(res, key)
            k--;
        }
    }
    return res
}