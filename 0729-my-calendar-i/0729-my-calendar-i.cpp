class MyCalendar {
public:
    
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
      auto it=mp.lower_bound(start);
        
      if(it!=mp.end() and it->second<end) return false;
        
       mp[end-1]=start;
        
        return true;
       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */