class Solution {
public:
    vector<vector<int>>ans;
    void helper(int val,int k,int n,vector<int>&v){
         // base condition
        
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        
        for(int i=val;i<=n;i++){        // traverse each element from [1,n];
             v.push_back(i);      // perform operation
             helper(i+1,k,n,v);   // call recursion
            v.pop_back();         // reverse operation (do backtrack)
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        helper(1,k,n,v);    // start from 1 as in qustion given [1,n]
        return ans;
    }
};