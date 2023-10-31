class Solution {
public:
    
  
    vector<int> findArray(vector<int>& pref) {
        
      int prev = pref[0];
        
        for(int i=1; i<pref.size(); i++)
        {
            int curr= pref[i];

            pref[i]= (prev ^ pref[i]);
            prev= curr;
        }
        
        return pref;
    }
};