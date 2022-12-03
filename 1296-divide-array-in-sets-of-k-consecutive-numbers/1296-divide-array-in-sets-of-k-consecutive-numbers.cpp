class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int looping=(nums.size()/k);
        if(looping*k!=nums.size()) return false;
    
        map<int,int>mp;
       
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       int cnt=0,ans=0;
        while(looping--){
            int prev=-1;
            for(auto &it:mp){
                
                if(it.second>0 and prev==-1){
                    ans++;
                   cnt++;
                    prev=it.first;
                    mp[it.first]--;
                }
               else  if(it.second>0 and prev!=-1 and prev+1==it.first){
                    ans++;
                   cnt++;
                   prev=it.first;
                    mp[it.first]--;
                }
                if(cnt==k){
                    cnt=0;
                    break;
                }
            }
        }
      
        return ans==nums.size();
               
    }
};