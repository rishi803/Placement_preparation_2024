class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>>ans;
        vector<pair<int,int>>v;
        
        for(int i=0;i<groupSizes.size();i++){
            v.push_back({groupSizes[i],i});
        }
        
        sort(v.begin(),v.end());
        
        vector<int>temp;
        
        for(int i=0;i<groupSizes.size();i++){
            
             
            
            if(temp.size()<v[i].first){
                temp.push_back(v[i].second);
            }
          if(temp.size()==v[i].first){
                ans.push_back(temp);
                temp.clear();
            }
            
        }
        if(!temp.empty()) ans.push_back(temp);
        
        return ans;
    }
};