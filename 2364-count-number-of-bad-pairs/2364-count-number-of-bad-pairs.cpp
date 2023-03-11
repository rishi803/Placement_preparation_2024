// Explanation:  [4 1 3 5]

// put [4-0] in map    mp[4-0]=mp[4]=1;

// search mp[1-1] in map (if ==mp.end()) means all previous elements are satisfying the property ( nums[j]-j != nums[i]-i ) so count all the previous element in our answer variable by "curszofmap" variable 

// we have not directly added size of map in answer because if mp[1]=2 then we know that there are two elements (two times 1) but mp.size() will only count its unique count i.e 1 so we have made a variable which will count total no. of elements present in map at each step

//  if ( mp.find(nums[i]-i)!=mp.end() ) then it means that, that amount of element is not bad because it is already present in map so in answer add total current size of map but also subtract that much amount of element which is present.  (if case)


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        int curszofmap=1;
        unordered_map<int,int>mp;
        mp[nums[0]-0]=1;
        
        long long ans=0;
        
        for(int i=1;i<nums.size();i++){
            
            if(mp.find(nums[i]-i)!=mp.end()){
                // cout<<ans<<endl;
                ans+=curszofmap-mp[nums[i]-i];
            }
            
            else ans+=curszofmap;
            
            mp[nums[i]-i]++;   // insert current element as (curr element - index of this element)
            curszofmap++;      // increase total count of element in current map
            
        }
        
        return ans;
    }
};