func putMarbles(weights []int, k int) int64 {
    var pairSum []int
    for i := 0; i< len(weights)-1; i++ {
        pairSum = append(pairSum, weights[i] + weights[i+1])
    }
    sort.Ints(pairSum)
    i, j := 0, len(pairSum)-1
    var x, y int
    for k > 1 {
        x += pairSum[i]
        y += pairSum[j]
        i++;
        j--;
        k--;
    }
    return int64(y - x)
}