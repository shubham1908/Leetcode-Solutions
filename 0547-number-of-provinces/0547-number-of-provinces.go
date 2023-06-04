type Dsu interface{
    find(u int) int
    union(u int, v int) int
    countComponent() int
}

type dsu struct {
    par []int
}

func newDsu(n int) Dsu {
    par := make([]int, n)
    for i := range par {
        par[i] = i
    }
    return &dsu{par: par}
}

func (d *dsu) find(u int) int {
    if d.par[u] != u {
        return d.find(d.par[u])
    }
    return u
}

func (d *dsu) union(u int,v int) int {
    a := d.find(u)
    b := d.find(v)
    
    d.par[b] = a
    return a
}

func (d *dsu) countComponent() int {
    set := make(map[int]struct{})
    
    for _, e := range d.par {
        set[d.find(e)] = struct{}{}
    }
    return len(set)
}



func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)
	d := newDsu(n)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j && isConnected[i][j] == 1 {
				d.union(i, j)
			}
		}
	}

    return d.countComponent()
}