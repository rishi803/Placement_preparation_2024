class Solution {
public:
    int countPairs(vector<int>& arr) {
    //        int n = arr.size();
    // unordered_map<int, int> freq;
    // for (int i = 0; i < n; i++) {
    //     freq[arr[i]]++;
    // }
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     freq[arr[i]]--;
    //     for (int j = 0; j <= 30; j++) {
    //         int target = (1 << j) - arr[i];
    //         if (freq.count(target)) {
    //             ans = (ans + freq[target]) % int (1e9+7);
    //         }
    //     }
    // }
    // return ans;
        
               int n = arr.size();
    unordered_map<int, int> freq;
    freq[arr[0]]=1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
       
        for (int j = 0; j <= 21; j++) {
            int target = (1 << j) - arr[i];
            if (freq.count(target)) {
                ans = (ans + freq[target]) % int (1e9+7);
            }
        }
         freq[arr[i]]++;
    }
    return ans;
    }
};