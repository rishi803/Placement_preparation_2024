class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last_seen_at;
        for (int i  = 0; i < nums.size(); ++i) {
            auto itr = last_seen_at.find(nums[i]);
            if (itr != last_seen_at.end() && i - itr->second <= k)
                return true;
            last_seen_at[nums[i]] = i;
        }   
        return false;
    }
};