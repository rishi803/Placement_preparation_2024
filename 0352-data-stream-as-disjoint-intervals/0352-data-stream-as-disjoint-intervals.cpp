class SummaryRanges {
public:
   
    set<int>st;
    
    SummaryRanges() {
       
    }
    
    void addNum(int value) {
      st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        if(st.empty()) return {};
        int start=*st.begin(),end=*st.begin();
        
          for(auto it=next(st.begin());it!=st.end();it++){
              int val=*it;
              if((val-end==1)){
                  end=val;
              }
              
              else{
                  ans.push_back({start,end});
                  start=val,end=val;
              }
          }

        ans.push_back({start,end});
        return ans;
    }
};

