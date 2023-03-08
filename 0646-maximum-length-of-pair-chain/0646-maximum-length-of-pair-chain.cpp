class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
      
        
        sort(pairs.begin(),pairs.end(),cmp);
        
          int ans=1,prev=pairs[0][1];
        // for(auto it:pairs) cout<<it[0]<<" "<<it[1]<<endl;
        
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>prev) {
                prev=pairs[i][1];
                ans++;
            }
        }
        
        return ans;
    }
};