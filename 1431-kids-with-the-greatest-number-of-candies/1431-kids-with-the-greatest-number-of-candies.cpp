class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        
        vector<bool>ans;
        int mx=*max_element(candies.begin(),candies.end());
        for(auto i:candies){
            if(i+extra>=mx) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};