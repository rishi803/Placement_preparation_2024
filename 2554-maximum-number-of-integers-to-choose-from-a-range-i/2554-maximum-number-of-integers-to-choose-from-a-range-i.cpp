class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       sort(banned.begin(),banned.end());
        int x=1;
        int sum=0,cnt=0;
        
        
        for(int i=1;i<=n;i++){
            if(find(banned.begin(),banned.end(),i)!=banned.end()) continue;
            else {
                sum+=i;
                if(sum>maxSum) break;
                cnt++;
            }
        }
        return cnt;
    }
};