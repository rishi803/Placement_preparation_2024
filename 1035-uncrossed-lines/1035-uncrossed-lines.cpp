class Solution {
public:
    
    int dp[501][501];
    
    int help(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(j==nums2.size() or i==nums1.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0,nottake=0;
        
        if(nums1[i]==nums2[j]){
            take=1+help(nums1,nums2,i+1,j+1);
        }
        
        nottake=max(help(nums1,nums2,i+1,j),help(nums1,nums2,i,j+1));
        
        return dp[i][j]=max(take,nottake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return help(nums1,nums2,0,0);
    }
};