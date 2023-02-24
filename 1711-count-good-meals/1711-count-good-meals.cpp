class Solution {
public:
   int countPairs(vector<int>& a) {
        unordered_map<int,int> lks;
        long long ans=0;
        for(int x : a){
            for(long i=1;i<=(1<<30);i*=2){
                if(lks.count(i-x)) ans+=lks[i-x];
            }
            lks[x]+=1;
        }
        return ans % (int)(1e9 + 7);
    }
};