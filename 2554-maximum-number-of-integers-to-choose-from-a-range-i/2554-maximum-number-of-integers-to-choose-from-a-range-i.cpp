class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int>mp;
        for(auto &i:banned) mp[i]++;
        long long sum=0,cnt=0;
        
        for(int i=1;i<=n;i++){
            
            if(mp[i]==0 and sum+i<=maxSum){
                cnt++;
                sum+=i;
            }
        }
        return cnt;
    }
};