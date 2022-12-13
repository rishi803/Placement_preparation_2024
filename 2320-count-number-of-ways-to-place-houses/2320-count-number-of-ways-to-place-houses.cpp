class Solution {
public:
    int countHousePlacements(int n) {
        if(n==1) return 4;
        long long ans=1;
        long long firstbase=1,secbase=2;
        for(int i=2;i<=n;i++){
           ans=(firstbase+secbase)%(int)(1e9+7);
            firstbase=secbase;
            secbase=ans;
        }
        return (ans*ans)%(int)(1e9+7);
    }
};