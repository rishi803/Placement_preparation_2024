class Solution {
public:
    
    long long help(vector<int>&arr1,vector<int>&arr2,int idx,int prev, map<pair<int, int>, int>&dp){
        
        if(idx==arr1.size()) return 0;
if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        
        long long change=INT_MAX,notchange=INT_MAX;
        
        if(arr1[idx]>prev){
            notchange=help(arr1,arr2,idx+1,arr1[idx],dp);
        }
        
    
            int getidx=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        
        if(getidx<arr2.size()){
            change=1+help(arr1,arr2,idx+1,arr2[getidx],dp); 
        }  
 
        
        return dp[{idx, prev}]= min(change,notchange);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
         map<pair<int, int>, int> dp;
        sort(arr2.begin(),arr2.end());
        int ans=help(arr1,arr2,0,-1,dp);
        return ans==INT_MAX?-1:ans;
    }
};