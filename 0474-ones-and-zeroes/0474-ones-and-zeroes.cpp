class Solution {
public:
    int dp[601][101][101];
    int help(vector<pair<int,int>>&v,vector<string>&strs,int num0,int num1,int idx){
        if(idx>=strs.size() or (num0==0 and num1==0)) return 0;
        if(v[idx].first>num0 or v[idx].second>num1) return dp[idx][num0][num1]=help(v,strs,num0,num1,idx+1);
        if(dp[idx][num0][num1]!=-1) return dp[idx][num0][num1];
        int include=1+help(v,strs,num0-v[idx].first,num1-v[idx].second,idx+1);
        int exclude=help(v,strs,num0,num1,idx+1);
        
        return dp[idx][num0][num1]=max(include,exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>v;
        for(auto &str:strs){
            int cnt0=0,cnt1=0;
            for(int i=0;i<str.size();i++){
                str[i]=='0'?cnt0++:cnt1++;
            }
            v.push_back({cnt0,cnt1});
        }
        return help(v,strs,m,n,0);
    }
};