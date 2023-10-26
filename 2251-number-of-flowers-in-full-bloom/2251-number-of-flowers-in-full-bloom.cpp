class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp;
        
        
        for(int i=0; i<flowers.size(); i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
     
        int flowercnt= 0;
        
       for(auto [key,value]: mp){
           flowercnt+= value;
           mp[key]= flowercnt;
       }
        vector<int> result;

        for (int i = 0; i < people.size(); i++) {
            auto ans = mp.lower_bound(people[i]);

            if (ans == mp.begin() and ans->first != people[i])
              {
                 result.push_back(0);
             }
            
            else if( ans != mp.begin() and ans->first != people[i])
            {
                ans--;
                result.push_back(ans->second);
            }
            
            else{
                result.push_back(ans->second);
            }
            
        }

        return result;
    }
};