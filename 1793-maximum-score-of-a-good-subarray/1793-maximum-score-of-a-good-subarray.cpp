class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left= k, right=k, ans= nums[k], mn= nums[k], sz= nums.size();
        int leftidx=k, rightidx=k;
        
        while((left > 0) or (right < sz-1))
        {
           if(left == 0 and right < sz-1){
                right++;
               mn= min(mn, nums[right]);
              
           }
            
            else if(right == sz-1 and left > 0){
                 left--;
                mn= min(mn, nums[left]);
               
            }
            
            else if ( nums[left-1] > nums[right+1]){
                left--;
                mn= min(mn, nums[left]);
            }
            
            else{
                right++;
                mn= min(mn, nums[right]);
            }
            // cout<<left<<" "<<right<<" "<<mn<<endl;
            ans= max(ans, mn * (right-left+1));
            
            // cout<<leftvalue<<" "<<rightvalue<<" "<<leftidx<<" "<<rightidx<<" "<<mn<<endl;
        }
        
        return ans;
    }
};