class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       sort(banned.begin(),banned.end());
        int x=1;
        int sum=0,cnt=0;
        
       unordered_map<int,int>mp;
        for(auto &i:banned) mp[i]=1;
        
        for(int i=1;i<=n;i++){
            if(mp[i]==1) continue;
            else {
                sum+=i;
                if(sum>maxSum) break;
                cnt++;
            }
        }
        return cnt;
    }
};