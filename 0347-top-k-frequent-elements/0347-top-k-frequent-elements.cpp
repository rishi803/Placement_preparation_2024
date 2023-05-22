class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        
        multimap<int,int,greater<int>>freq;
        for(auto [x,y]:mp) freq.insert(pair<int, int>(y, x));
        
        vector<int>ans;
        
       for(auto &[x,y]:freq){
           if(k==0) return ans;
           else k--,ans.push_back(y);
       }
        return ans;
       
        }
};