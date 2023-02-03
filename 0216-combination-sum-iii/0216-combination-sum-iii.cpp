class Solution {
public:
    
    void help(vector<vector<int>>&ans,int idx,vector<int>&temp,int size_needed,int target,int sum){
        
    if(sum>target) return;             // if sum>target you will never get the answer so go back
        
    if(temp.size()==size_needed and sum==target ){       // when you have to store the combination in 2d vector
       ans.push_back(temp);
        return;
    }
        
        for(int i=idx;i<=9;i++){
            
         sum=sum+i;           // operation 
         temp.push_back(i);
             
        help(ans,i+1,temp,size_needed,target,sum);
            
        sum=sum-i;              // backtrack
        temp.pop_back();
        

        }
        
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;     // make a 2d vector to store all the combinations equal to target
        vector<int>temp;            // make a temp vector that will store the numbers sum to target
        help(ans,1,temp,k,n,0);
        return ans;
        
    }
};