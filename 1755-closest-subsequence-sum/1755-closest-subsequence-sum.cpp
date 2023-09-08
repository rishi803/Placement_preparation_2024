class Solution {
public:
    
    void generate_subset(vector<int>&nums, vector<int>&v, int idx, int sz, int sum){
        
           if(idx >= sz){
               v.push_back(sum);
               return;
           }
    
          generate_subset(nums, v, idx+1, sz, sum+nums[idx]);
          generate_subset(nums, v, idx+1, sz, sum);
        
        
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        
    int n = nums.size();

    // Generate all possible sums for the first half of nums
    vector<int> sums1;
    generate_subset(nums, sums1, 0, n/2, 0);
        
    // Generate all possible sums for the second half of nums
    vector<int> sums2;
    generate_subset(nums, sums2, n/2, nums.size(), 0);
        
// for(int i:sums1) cout<<i<<" ";
//         cout<<endl;
//         for(int i:sums2) cout<<i<<" ";
//         cout<<endl;
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