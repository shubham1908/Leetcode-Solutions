func eventualSafeNodes(graph [][]int) []int {
    n := len(graph)
    visited := make([]int, n)
    for i := 0;i<n;i++ {
        visited[i] = 0
    }
    
    for i:=0;i<n;i++ {
        if visited[i] == 0 {
            dfs(i, visited, graph)
        }
    }
    
    ans := []int{}
    for i:=0;i<n;i++ {
        if visited[i] == 2 {
            ans = append(ans, i)
        }
    }
    return ans
}

func dfs(node int, visited []int, graph [][]int) int {
    visited[node] = 1
    if len(graph[node]) == 0 {
        visited[node] = 2
        return 2
    }
    x := 0
    for i:=0;i<len(graph[node]);i++ {
        if visited[graph[node][i]] == 1 {
            x = -1
        }
        if visited[graph[node][i]] == 0 {
            y := dfs(graph[node][i], visited, graph)
            if y == -1 {
                x = -1
            }
        }
    }
    if x != -1 {
        visited[node] = 2
        return 2
    }
    return -1
}