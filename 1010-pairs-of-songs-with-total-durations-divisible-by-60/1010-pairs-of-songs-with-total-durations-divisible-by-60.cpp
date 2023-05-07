class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       unordered_map<int,int>mp;
        
        for(auto i:time){
            mp[i%60]++;
        }
        int ans=0;
        
        for(auto i:time){
             mp[i%60]--;
            
            if(i%60==0){
               int find=0;
                ans+=mp[find];
            }
            else{
                 int find=60-(i%60);
          
        // cout<<i<<" "<<mp[find]<<endl;
          ans+=mp[find];  
            }
        
          // mp.erase(find);
          
        }
        
        return ans;
    }
};