class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int>mp;
        int res=1;
        
        for(int i=0;i<arr.size();i++){
            
            int ans=mp[arr[i]-difference];
            if(ans>0){
                mp[arr[i]]=ans+1;
                 res=max(res,mp[arr[i]]);
            }
            else mp[arr[i]]=1;
        }
        return res;
    }
};