class Solution {
public:
  
     vector<int>temp;
    
    void help(vector<int>&nums,int idx, int bit_or){
        
        temp.push_back(bit_or);
        // cout<<bit_or<<endl;
        for(int i=idx;i<nums.size();i++){
            
            help(nums,i+1,bit_or|nums[i]);
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
         help(nums,0, 0);
        int mx_element=*max_element(temp.begin(),temp.end());
        
        int cnt=count(temp.begin(),temp.end(),mx_element);
         return cnt;
    }
};