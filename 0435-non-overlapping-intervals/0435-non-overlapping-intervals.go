func eraseOverlapIntervals(intervals [][]int) int {
    sort.Slice(intervals, func(i, j int) bool {
        if intervals[i][1] == intervals[j][1] {
            return intervals[i][0] < intervals[j][0]
        }
        return intervals[i][1] < intervals[j][1]
    })
    
    cnt := 0
    end:= -10000000
    for _, interval := range intervals {
        if interval[0] < end {
            cnt++
        } else {
            end = interval[1]
        }
    }
    return cnt
}