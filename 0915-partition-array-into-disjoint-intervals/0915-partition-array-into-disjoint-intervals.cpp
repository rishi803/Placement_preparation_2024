//   Easier Version

// if you are on ith element then max element on left of ith element should be less that min element of right of ith element

//    [5, 0, 3, 8, 6]

//   [5]      [0,3,8,6]    max(5)=5     and    min(0,3,8,6)=0    (5>0)  cnt++
//   [5,0]    [3,8,6]      max(5,0)=5   and    min(3,8,6)=3      (5>3)   cnt++
//   [5,0,3]  [8,6]        max (5,0,3)  and    min(8,6)=6        (5<6)   break;  we got the valid subarray


class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int sz=nums.size();
        vector<int>min_on_right(sz);
        min_on_right[sz-1]=nums[sz-1];
        
        for(int i=sz-2;i>=0;i--){
            
            min_on_right[i]=min(min_on_right[i+1],nums[i]);
        }
        
        int cnt=1;
        
        int max_on_left=nums[0];
        
        for(int i=0;i<=sz-2;i++){
            
            max_on_left=max(max_on_left,nums[i]);
            
            if(max_on_left>min_on_right[i+1]) cnt++;
            
            else break;
        }
        
        return cnt;
    }
};