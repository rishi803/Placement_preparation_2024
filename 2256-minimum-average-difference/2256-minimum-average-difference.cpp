class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
           
        }
        
        int mnidx=INT_MAX,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int f=(pre[i])/(i+1);
            int l=0;
            if(i==nums.size()-1) l=0;
            else
                l=(pre[nums.size()-1]-pre[i])/(nums.size()-i-1);
          
            int temp=abs(f-l);
           if(temp<ans){
               ans=temp;
               mnidx=i;
           }
        }
        return mnidx;
    }
};