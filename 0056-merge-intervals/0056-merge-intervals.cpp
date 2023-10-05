class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
          vector<vector<int>>ans;
        
          sort(intervals.begin(), intervals.end());
          
           int prevst= intervals[0][0];
           int prevend= intervals[0][1];
        
          ans.push_back({prevst,prevend});
        
        for(int i=1; i<intervals.size(); i++){
            
            if(intervals[i][0] > prevend){
                prevst= intervals[i][0];
                prevend= intervals[i][1];
                
                ans.push_back({prevst, prevend});
            }
            
            else{
                prevend= max(prevend, intervals[i][1]);
                ans.back()= {prevst,prevend};
            }
        }
        return ans;
    }
};