func canFinish(numCourses int, prerequisites [][]int) bool {
    pre := make([][]int, numCourses)
    
    for _, preReq := range prerequisites {
        pre[preReq[0]] = append(pre[preReq[0]], preReq[1])
    }
    
    level := make([]int, numCourses)
    
    // -numCourses-1 -> represents haven't picked yet
    // numCourses+1  -> want to pick but level not defined yet
    for i:=0;i<numCourses;i++ {
        level[i] = -numCourses-1
    }
    for i:=0;i<numCourses; i++{
        if level[i] == -numCourses-1 {
            if !helper(i, pre, level, numCourses){
                return false
            }
        }
    }
    return true
}

func helper(course int, pre [][]int, level []int, numCourses int) bool {
    if len(pre[course]) == 0 {
        level[course] = 0
        return true
    }
    if level[course] == numCourses+1 { // already want to pick (cycle)
        return false
    }
    level[course] = numCourses+1
    lvl := -numCourses-1
    for _, preCourse := range pre[course] {
        if level[preCourse] == numCourses+1 {
            return false
        }
        if level[preCourse] == -numCourses-1 {
            if !helper(preCourse, pre, level, numCourses){
                return false
            }
            if lvl < level[preCourse] +1 {
                lvl= level[preCourse] +1
            }
        } else {
            if lvl < level[preCourse] +1 {
                lvl= level[preCourse] +1
            }
        }
    }
    level[course] = lvl
    return true
}