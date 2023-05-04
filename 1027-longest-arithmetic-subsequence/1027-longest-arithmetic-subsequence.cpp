// memo even gives TLE
// Approach is: at each index find diff of each of its previous index and check whether curr index with difference occur at any previous index with same difference if so then increment its value by 1 if not then this means that a new subsequence is going to start at this index with difference diff with minimum elment 2 (previous one and current one)

class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size(), res=0;
    
    vector<vector<int>> dp(n, vector<int>(1001,0));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
           
            int diff = nums[i] - nums[j] +500; // to handle -ve differences
            
            dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;  // there will be atleast 2 element forming arithmetic (prev one and curr one)
            
             // cout<<"j--> "<<"dp["<<j<<"]["<<diff<<"] i--> dp["<<i<<"]["<<diff<<"] = "<<dp[i][diff]<<endl;
            res = max(res, dp[i][diff]); 
        }
        // cout<<endl;
    }
    
    return res;
}
};