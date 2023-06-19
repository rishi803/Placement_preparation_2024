class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int alt=0,sum=0;
        int ans=0;
        
        for(auto i:gain){
            sum+=i;
            ans=max(ans,sum);
        }
        
        return ans;
    }
};