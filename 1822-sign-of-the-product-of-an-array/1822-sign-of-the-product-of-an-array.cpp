class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int pro=0;
        
        for(auto i:nums) {
            if(i<0) pro++;
            if(i==0) return 0;
        }
        
        if(pro%2==0) return 1;
        else return -1;
    }
};