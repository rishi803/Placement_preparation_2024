class MyCalendar {
public:
    
    map<int,int>mp;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int overlap= 0;
        
        for(auto [key,value]:mp){
            overlap+=value;
            
            if(overlap >= 2){     // do not book this (do not add this in map)
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        
        return true;
    }
};

