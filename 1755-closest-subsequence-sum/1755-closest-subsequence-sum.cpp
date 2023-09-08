class Solution {
public:
    

    int minAbsDifference(vector<int>& nums, int goal) {
        
         int n = nums.size();
    int m = n / 2;

    // Generate all possible sums for the first half of nums
    vector<int> sums1 = {0};
    for (int i = 0; i < m; i++) {
        vector<int> curr_sums;
        for (int s : sums1) {
            curr_sums.push_back(s + nums[i]);
            curr_sums.push_back(s);
        }
        sums1 = curr_sums;
    }

    // Generate all possible sums for the second half of nums
    vector<int> sums2 = {0};
    for (int i = m; i < n; i++) {
        vector<int> curr_sums;
        for (int s : sums2) {
            curr_sums.push_back(s + nums[i]);
            curr_sums.push_back(s);
        }
        sums2 = curr_sums;
    }

    // Sort the sums from the second half
    sort(sums2.begin(), sums2.end());

    // Initialize the minimum absolute difference
    int min_abs_diff = INT_MAX;

    // Loop through the sums from the first half and find the closest sum in the second half
    for (int s1 : sums1) {
        int target = goal - s1;
        int left = 0, right = sums2.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int s2 = sums2[mid];
            int current_diff = abs(s1 + s2 - goal);
            min_abs_diff = min(min_abs_diff, current_diff);

            if (s2 < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return min_abs_diff;
    }
};