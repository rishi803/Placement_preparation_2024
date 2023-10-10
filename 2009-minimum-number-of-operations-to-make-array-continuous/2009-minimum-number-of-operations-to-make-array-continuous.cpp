class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i =0 ; i<n; i++){
             s.insert(nums[i]);
        }
        vector<int>uniq;
        for(int i: s){
             uniq.push_back(i);
        }
        sort(uniq.begin(),uniq.end());
          int ans = INT_MAX;
        for(int i=0;i<uniq.size();i++)
        {
            int start = uniq[i];
            int last = start+n-1;
            
            vector<int>::iterator upper=upper_bound(uniq.begin(),uniq.end(),last);
            int len = upper- uniq.begin();
            ans = min(ans,n-(len-i));
            
        }
       return ans;
    
    }
};