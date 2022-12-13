class Solution {
public:
    int DP(vector<int>& arr, vector<int>& dp, int n, int ind){
        if(ind >= n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int i = ind;
        int sum = 0;
        while(i < n && arr[i] == arr[ind]){
            sum += arr[ind];
            i++;
        }
        
        while(i < n && arr[i] == arr[ind] + 1)
            i++;
        
        int pick = sum + DP(arr, dp, n, i);
        int notPick = DP(arr, dp, n, ind + 1);
        return dp[ind] = max(pick,notPick);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        sort(nums.begin(),nums.end());
        return DP(nums, dp, n, 0);
        
    }
};