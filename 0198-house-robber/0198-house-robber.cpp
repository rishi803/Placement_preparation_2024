class Solution {
public:
   
    vector<int>memo;
    
    
   int help(vector<int>& nums, int idx) {
           if (idx >= nums.size()) {
            return 0;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

        int money = 0;

        for (int i = idx; i < nums.size(); ++i) {
            int current = nums[i] + help(nums, i + 2);
            money = std::max(money, current);
        }

        memo[idx] = money;
        return money;
    }
    
    int rob(vector<int>& nums) {
        memo.resize(nums.size(),-1);
      return  help(nums,0);
      
    }
};