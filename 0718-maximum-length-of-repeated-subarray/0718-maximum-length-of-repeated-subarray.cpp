// longest increasing substring 

class Solution {
public:
    ////////////////////////////////// Tabulation //////////////////////////////////
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),0));
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(i==0 and nums1[i]==nums2[j]){
                    dp[i][j]=1;
                    ans=1;
                }
                if(j==0 and nums2[j]==nums1[i]){
                    dp[i][j]=1;
                    ans=1;
                }
            }
        }
    
        for(int i=1;i<nums1.size();i++){
            for(int j=1;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j]+=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};