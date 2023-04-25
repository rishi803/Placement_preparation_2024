class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        vector<long long>ans(arr.size(),0);
        unordered_map<int,vector<long long>>mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        for(auto &it:mp){
            vector<long long>idx=it.second;
            
            vector<long long>prefix(idx.size());
            long long totalsum=0;
            prefix[0]=idx[0];
            totalsum=idx[0];
            
            for(int i=1;i<idx.size();i++){
                prefix[i]=prefix[i-1]+idx[i];
                totalsum=prefix[i];
            }
            
            for(int i=0;i<idx.size();i++){
                long long leftcnt=i;                //  0 1 2 3 (if 1 then leftcnt=1 and rightcnt=2)
                long long rightcnt= idx.size()-i-1;
                
                long long leftsum= prefix[i]-idx[i];
                long long rightsum= totalsum-prefix[i];
                
                ans[idx[i]]= abs(idx[i]*leftcnt-leftsum)+ abs(idx[i]*rightcnt-rightsum);
            }
        }
        
        return ans;
    }
};