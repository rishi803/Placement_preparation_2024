class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        long long flag=-1,temp=k,idx=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]-(i+1)==k){
                idx=i;
                flag=nums[i];
                break;
            }
            if( nums[i]-(i+1)>k){
                // cout<<nums[i]<<endl;
                
                if(i==0) {
                    return (temp*(temp+1))/2;
                }
                else
                flag=nums[i-1]+temp;
                break;
            }
            idx=i;
            temp=k-(nums[i]-(i+1));
        }
        // cout<<flag<<endl;
        
        if(flag!=-1){
            long long tsum=(flag*(flag+1))/2;
            long long sum=0;
            for(int i=0;i<=idx;i++){
                
                
                sum+=nums[i];
            }
            
            return tsum-sum;
        }
        
        else{
            int miss=nums[nums.size()-1]-nums.size();
             
            long long temp=nums[nums.size()-1];
            
            long long copy=temp;
            long long tsum=(copy*(copy+1))/2;
            k-=miss;
            for(int i=0;i<nums.size();i++){
                tsum-=nums[i];
            }
            
            while(k--){
                
                temp++;
                tsum+=temp;
                
            }
            return tsum;
        }
    }
};