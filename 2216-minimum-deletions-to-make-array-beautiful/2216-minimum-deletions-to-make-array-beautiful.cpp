class Solution {
public:

 // above approach gives TLE as we are actually shifting all elements again and again.Actually we do not do this

int minDeletion(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1] and (i - ans) % 2 == 0) ans++; // (i-ans) will give current index of element
        return ans + (nums.size() - ans) % 2;
    }
};