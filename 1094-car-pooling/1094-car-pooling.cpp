class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       map<int,int>mp;
        int passenger=0;
        
        for(auto &i:trips){
            mp[i[1]]+=i[0];
            mp[i[2]]+=-i[0];
            
           
        }
         for(auto &it:mp){
                passenger+=it.second;
                if(passenger>capacity) return false;
            }
        return true;
    }
};