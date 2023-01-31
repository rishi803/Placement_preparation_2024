class Solution {
public:
    int LIS(int prev_idx,int idx,vector<pair<int,int>>&v,vector<vector<int>>&dp)
    {
        if(idx>=v.size()) return 0;
        if(dp[prev_idx+1][idx]!=-1) return dp[prev_idx+1][idx];
        int pick=0,notpick=0;
        if(prev_idx==-1||v[idx].second>=v[prev_idx].second){
            pick=v[idx].second+LIS(idx,idx+1,v,dp);
        }
        notpick=0+LIS(prev_idx,idx+1,v,dp);
        return dp[prev_idx+1][idx]=max(pick,notpick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans=0,n=ages.size();
        vector<pair<int,int>>v;
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        int idx=0,prev_idx=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LIS(prev_idx,idx,v,dp);
    }
};