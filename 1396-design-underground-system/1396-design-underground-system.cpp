class UndergroundSystem {
public:
    
    unordered_map<int,pair<int,string>>mp;
    map<string,pair<int,int>>temp;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string currentst, int t) {
        mp[id]={t,currentst};
    }
    
    void checkOut(int id, string currentst, int t) {
      auto &[prevtime,prevst]=mp[id];
       
        
       string hash=prevst+"#"+currentst;
       int time=t-prevtime;
       
        if(temp[hash].first>0){
            auto &[key,val]=temp[hash];
            key+=time;
            val+=1;
        }
        else{
            temp[hash]={time,1};
        }
        
    }
    
    double getAverageTime(string start, string end) {
        auto &[key,val]=temp[start+"#"+end];
        return double(key)/double(val);
    }
};

