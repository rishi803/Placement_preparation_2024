// using ---> lower bound by storing end-1 as it is excluded and start is included if lower bound of start is searched then end-1 will save us from wrong ans as it give first occurence and if not present then give next element iterator

// using ---> upper bound by storing end as it is excluded and if upper bound of start is searched then it give iterator to next occurence of it whether element is present or not

// using prefix sum trick

// dry run for --  ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
// [[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]

class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // cout<<"St = "<<start<<" End = "<<end<<" ";
      auto it=mp.upper_bound(start);
      if(it!=mp.end() and it->second<end) {
          // cout<<"ubf "<<it->first<<" ";
           return false;}
       // else if(it!=mp.end()) cout<<"ub "<<it->first<<" ";
        mp[end]=start;
        // for(auto &it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */