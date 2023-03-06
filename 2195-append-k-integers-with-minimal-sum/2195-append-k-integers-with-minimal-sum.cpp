// concept used that if all element is in the range 1 to 10^9 then each index should have index+1 as value

// ex:  [1,4,6]   it should be like as [1,2,3,4,5,6]

// means when we are at 4 we are missing 2 and 3 (HOW==> nums[i]-(i+1)=4-2=2 element missing)

// when we are at 6 we are missing 2,3,5 (HOW==> nums[i]-(i+1)=6-3=3 element missing)

// WORKING OF nums[i]-(i+1) this means at ith index we should have i+1 as value but we currently having nums[i] as element so finding difference between these values if it is 0 means it is fine else it has that much element missing  EX: [1,2,3,5] upto 3 it is fine no missing but when we find 5 we see that 4 is missing (nums[3]-(3+1)=1 element missing)

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end()); // so that we only deal with unique element
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        long long flag=-1,temp=k,idx=0;
        
        for(int i=0;i<nums.size();i++){
            
           
            
            if(nums[i]-(i+1)==k){
                idx=i;                   
                flag=nums[i]; // don't need prev element this current element is last 
                break;
            }
            if( nums[i]-(i+1)>k){
                // cout<<nums[i]<<endl;
                
                if(i==0) {                           // for test case [3] and k=1
                    return (temp*(temp+1))/2;
                }
                else                          // else prev element + temp [1,3,10] and k=2 (flag=3+1)
                flag=nums[i-1]+temp;
                break;
            }
            idx=i;
            temp=k-(nums[i]-(i+1));   // calculate this at each step such that if nums[i]-(i+1)>k we use it 
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