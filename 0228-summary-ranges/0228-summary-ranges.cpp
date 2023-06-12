class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string>ans;
        
        string temp=to_string(nums[0]),temp1;
        
        for(int i=1;i<nums.size();i++){
            
          
          
              if(nums[i]==nums[i-1]+1){
                   temp1=to_string(nums[i]);
              }
               
            else{
                if(!temp1.size()) ans.push_back(temp);
                else{
                    ans.push_back(temp+"->"+temp1);
                }
                temp=to_string(nums[i]);
                temp1.clear();
            }
                
            }
        if(!temp1.size()) ans.push_back(temp);
                else{
                    ans.push_back(temp+"->"+temp1);
                }
      
        return ans;
    }
};