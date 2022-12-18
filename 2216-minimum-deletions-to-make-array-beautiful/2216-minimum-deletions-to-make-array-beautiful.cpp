class Solution {
public:
//     int minDeletion(vector<int>& nums) {
//         int cnt=0;
//         for(int i=0;i<nums.size(); ){
//              while(i<nums.size()-1 and i%2==0 and nums[i]==nums[i+1]){
//                  nums.erase(nums.begin()+i);
//                  cnt++;
//                  if(nums[i]!=nums[i+1]) i++;
//              }
          
//                 i++;
            
//         }
//         return nums.size()%2!=0 ? cnt+1 : cnt;
//     
// }
 // above approach gives TLE as we are actually shifting all elements again and again.Actually we do not do this

int minDeletion(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1] and (i - ans) % 2 == 0) ans++; // (i-ans) will give current index of element
        return ans + (nums.size() - ans) % 2;
    }
};