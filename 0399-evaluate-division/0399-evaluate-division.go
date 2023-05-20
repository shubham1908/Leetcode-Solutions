type ls struct {
    node string
    value float64
}

var res float64
var adj map[string][]ls
var vis map[string]bool


func dfs(u string, v string, mul float64) bool {
    lst, ok := adj[u]
    if !ok {
        return false
    }
    if u == v && adj[u] != nil {
        res = mul
        return true
    }
    
    vis[u] = true    
    for _, val := range lst {
        if !vis[val.node] {
            if dfs(val.node, v, val.value * mul) {
                vis[u] = false
                return true
            }
        }
    }
    vis[u] = false
    return false
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    adj = make(map[string][]ls)
    vis = make(map[string]bool)
    
    for ind, eq := range equations {
        adj[eq[0]] = append(adj[eq[0]], ls{
            node: eq[1],
            value: values[ind],
        })
        adj[eq[1]] = append(adj[eq[1]], ls{
            node: eq[0],
            value: 1/values[ind],
        })
        vis[eq[0]] = false
        vis[eq[1]] = false
    }
    
    var ans []float64
    for _, query := range queries {
        res = 1
        if dfs(query[0], query[1], 1) == true {
            ans = append(ans, res)
        } else {
            ans = append(ans, -1.0)
        }
    }
    return ans
}