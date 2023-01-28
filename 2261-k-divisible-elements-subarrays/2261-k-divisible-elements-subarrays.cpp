class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n=nums.size();
        set<vector<int>>ans;
        
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>mp;
            int ct=0;
            for(j=i;j<n;j++)
            {
                mp.push_back(nums[j]);
                if(nums[j]%p==0)
                    ++ct;
                if(ct>k)
                    break;
                ans.insert(mp);
                    
            }
        }
        return ans.size();
    }
};