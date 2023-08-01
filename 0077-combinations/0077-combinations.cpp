class Solution {
public:
    vector<vector<int>>ans;
    
    void help(int n,int k,int idx,vector<int>&temp){
        
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            help(n,k,i+1,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>temp;
          help(n,k,1,temp);
        return ans;
    }
};