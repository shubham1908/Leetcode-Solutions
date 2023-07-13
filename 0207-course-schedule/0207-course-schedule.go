func canFinish(numCourses int, prerequisites [][]int) bool {
    adj := make([][]int, numCourses)
    inDegree := make([]int, numCourses)
    for _, preReq := range prerequisites {
        adj[preReq[1]] = append(adj[preReq[1]], preReq[0])
        inDegree[preReq[0]]++
    }
    
    queue := []int{}
    for i:=0;i<numCourses;i++ {
        if inDegree[i] == 0 {
            queue = append(queue, i)
        }
    }
    cnt := 0
    for len(queue) != 0 {
        course := queue[0]
        queue = queue[1:]
        cnt++
        for _, c := range adj[course] {
            inDegree[c]--
            if inDegree[c] == 0{
                queue = append(queue, c)
            }
        }
    }
    return cnt == numCourses
}