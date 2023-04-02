class Solution {
public:
    
    int lowerbound(long long target,vector<int>&nums,int l,int h){
        
        
        
        while(l<=h){
         int mid=l+(h-l)/2;
         
          if(nums[mid]>=target){
              h=mid-1;
          }
         else if(nums[mid]<target){
             l=mid+1;
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