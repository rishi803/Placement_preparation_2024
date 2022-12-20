class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        for(auto &it:logs){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        int mxsum=0,sum=0,ans=0;
        for(auto [fir,sec]:mp){
            sum+=sec;
            if(sum>mxsum){
                mxsum=sum;
                ans=fir;
            }
        }
        return ans;
    }
};