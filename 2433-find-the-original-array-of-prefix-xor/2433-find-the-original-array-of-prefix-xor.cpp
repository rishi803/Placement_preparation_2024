class Solution {
public:
    
    int help(int number, int resultant){
        return number ^ resultant;
    }
    vector<int> findArray(vector<int>& pref) {
        
        vector<int>ans;
     
        
        ans.push_back(pref[0]);
        
        for(int i=1; i<pref.size(); i++)
        {
            int result= help(pref[i-1], pref[i]);
            
            ans.push_back(result);
        }
        
        return ans;
    }
};