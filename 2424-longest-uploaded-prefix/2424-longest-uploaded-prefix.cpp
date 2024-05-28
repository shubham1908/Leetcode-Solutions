class LUPrefix {
public:
    vector<int> v;
    int up;
    int N;
    LUPrefix(int n) {
        v.resize(n, 0);
        up = 0;
        N = n;
    }
    
    void upload(int video) {
        v[video-1]=1;
    }
    
    int longest() {
        while(up<N && v[up] ==1){
            up++;
        }
        return up;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */