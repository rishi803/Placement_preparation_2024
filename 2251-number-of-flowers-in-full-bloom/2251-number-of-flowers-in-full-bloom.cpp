class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp;
        
        
        for(int i=0; i<flowers.size(); i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
            // mxsz= max({mxsz,flowers[i][0],flowers[i][1]});
        }
     
        set<pair<int,int>>v;
        int flowercnt= 0;
        
       for(auto [idx,flowers]: mp){
           flowercnt+= flowers;
           v.insert({idx,flowercnt});
       }
        
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        vector<int>result;
        
        for(int i=0; i<people.size(); i++){
          std::set<std::pair<int, int>>::iterator ans = v.lower_bound({people[i],0});
            
            if(ans == v.begin() and ans->first != people[i]){
                result.push_back(0);
            }
            
            else if(ans->first != people[i] and ans != v.begin()) {
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