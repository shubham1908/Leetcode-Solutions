class MyCalendar {
public:
    map<int, int> mp;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        if(it != mp.end()){
            if((*it).first < end){
                return false;
            }
        }
        if(it != mp.begin()){
            it = prev(it);
            if((*it).second > start){
                return false;
            }
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// start s e end , start s end e, x start end y, x start y end

// start end s e

