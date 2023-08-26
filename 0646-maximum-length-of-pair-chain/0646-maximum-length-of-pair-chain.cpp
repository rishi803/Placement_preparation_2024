class Solution {
public:
    
    int help(vector<vector<int>>&pairs, int idx, int prev){
        if(idx >= pairs.size()) return 0;
        
        if(pairs[idx][0] > prev) return 1 + help(pairs, idx+1, pairs[idx][1]);
        
        return help(pairs, idx+1, prev);
        
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), [&](vector<int>&a, vector<int>&b){
             return a[1] < b[1];
        });
        
       return help(pairs, 0, -10000);
    }
};