func maxValue(events [][]int, k int) int {
    sort.SliceStable(events, func(i, j int) bool {
            return events[i][0] < events[j][0]
    })
    mem := make(map[[3]int]int, 0)
    return dfs(&events, &mem, 0, -1, k)
}

func dfs(events *[][]int, mem *map[[3]int]int, idx, time, quota int) int {
    key := [3]int{idx, time, quota}
    if idx == len(*events) || quota == 0 {
        return 0
    } else if v, ok := (*mem)[key]; ok {
        return v
    }
    
    left := dfs(events, mem, idx+1, time, quota)

    right := 0
    if time < (*events)[idx][0]{
        right = dfs(events, mem, idx+1, (*events)[idx][1], quota-1) + (*events)[idx][2]
    }
    if left > right {
        (*mem)[key] = left
    } else {
        (*mem)[key] = right
    }

    return (*mem)[key]
}
