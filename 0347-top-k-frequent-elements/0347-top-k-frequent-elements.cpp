class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>ans;
        vector<int>res;
        int x=0;
        for(int i=0;i<nums.size();i++){
           ans[nums[i]]++; 
        }
         priority_queue<pair<int,int>> pq;
        // sort(ans.begin(),ans.end(),sortby_sec);
          for(auto it=ans.begin();it!=ans.end();it++){
              // cout<<it->first<<" "<<it->second<<"bas ";
              pq.push(make_pair(it->second, it->first));}
        
             while( k--){
                 res.push_back(pq.top().second);
                pq.pop();
                 
              }
       
        return res;
    }
};