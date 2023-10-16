class Solution {
public:
    void helper(vector<int>&res,int r,int n){
        long long ans=1;
        for(int i=n,j=1;i>r;i--,j++){
            ans=(ans*i)/j;
        }
        res.push_back(ans);
    }
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        
        
        for(int r=0;r<=rowIndex;r++){
            helper(res,r,rowIndex);
        }
       
        return res;
    }
};