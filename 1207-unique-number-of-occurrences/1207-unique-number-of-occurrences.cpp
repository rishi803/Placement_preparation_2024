class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        arr.clear();
        for(auto &it:mp){
            mp1[it.second]++;
        }
        
        return mp1.size()==mp.size();
    }
};