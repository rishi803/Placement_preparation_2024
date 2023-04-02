class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long target=((success-1)/spells[i])+1;
            int lb=lower_bound(potions.begin(),potions.end(),target)-potions.begin();
            ans.push_back(potions.size()-lb);
        }
        return ans;
    }
};