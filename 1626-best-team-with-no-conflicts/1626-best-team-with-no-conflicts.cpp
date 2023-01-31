class Solution {
public:
    vector<vector<int>>dp;
    int help(vector<pair<int,int>>&v,int prev,int idx){
        if((idx>=v.size())) return 0;
        if(dp[prev+1][idx]!=-1) return dp[prev+1][idx];
        int take=0,nottake=0;
        if(prev==-1||v[idx].second>=v[prev].second){
        take+=v[idx].second+help(v,idx,idx+1);}
        nottake+=help(v,prev,idx+1);
        
        return dp[prev+1][idx]=max(take,nottake);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        dp.resize(scores.size()+1,vector<int>(scores.size()+1,-1));
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        return help(v,-1,0);
    }
};