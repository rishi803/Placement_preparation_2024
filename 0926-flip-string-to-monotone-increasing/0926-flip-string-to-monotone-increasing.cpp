//test "0101100011"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntflip=0,cnt1=0,ans=INT_MAX;
        for(auto &i:s){
            
            if(i=='1'){
                
                cnt1++;
            }
            
            else cntflip++;
            
            cntflip=min(cnt1,cntflip);
            
        }
        return cntflip;
    }
};