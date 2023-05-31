class UndergroundSystem {
public:
    
    unordered_map<int,pair<int,string>>mp;
    unordered_map<string,pair<int,int>>temp;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string currentst, int t) {
        mp[id]={t,currentst};
    }
    
    void checkOut(int id, string currentst, int t) {
      auto &[prevtime,prevst]=mp[id];
       
        
       string hash=prevst+"#"+currentst;
       int time=t-prevtime;
       
            auto &[key,val]=temp[hash];
            key+=time;
            val+=1;
       
        mp.erase(id);
        
    }
    
    double getAverageTime(string start, string end) {
        auto &[key,val]=temp[start+"#"+end];
        return double(key)/double(val);
    }
};

