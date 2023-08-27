class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_map<int,int>mp;
        long long ans=0;
        int cnt=0;
        for(int i=1; i<1000001; i++){
            if(mp[target-i] <= 0){
                ans+=i;
                cnt++;
                mp[i]++;
            }
           if(cnt == n) return ans;
        }
        return ans;
    }
};