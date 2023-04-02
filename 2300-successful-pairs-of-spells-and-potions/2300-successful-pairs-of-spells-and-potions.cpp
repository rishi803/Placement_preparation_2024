class Solution {
public:
    
    int lowerbound(long long target,vector<int>&nums,int l,int h){
        
        int mid=l+(h-l)/2;
        
        while(l<=h){
         
         
          if(nums[mid]>=target){
             return lowerbound(target,nums,l,mid-1);
          }
         else if(nums[mid]<target){
           return  lowerbound(target,nums,mid+1,h);
         }
        }
        return l;
        
       
        
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long target=((success-1)/spells[i])+1;
            int lb=lowerbound(target,potions,0,potions.size()-1);
            ans.push_back(potions.size()-lb);
        }
        return ans;
    }
};