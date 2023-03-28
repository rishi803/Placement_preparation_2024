class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       
        map<int,int>mp;
        int j=0;
        for(auto &i:intervals){
            mp[i[0]]=j++;
        }
        vector<int>ans;
        
        for(auto &i:intervals){
            
            auto idx=mp.lower_bound(i[1]);
            
            if(idx!=mp.end()) ans.push_back(idx->second);
            else ans.push_back(-1);
        }
        
        return ans;
    }
};