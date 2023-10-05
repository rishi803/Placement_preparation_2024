class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
          sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b){
              return a[1] < b[1];
          });
        
        int prevst= intervals[0][0];
        int prevend= intervals[0][1];
        int remove= 0;
        
           for(int i=1; i<intervals.size(); i++){
               
               if(intervals[i][0] < prevend){    // if overlapping remove which have less range
                   remove++; 
                   
                   prevst= max(prevst,intervals[i][0]);      
                   prevend= min(prevend,intervals[i][1]);
               }
               
              else{
                   prevst= intervals[i][0];
                   prevend=intervals[i][1];
              }
               // cout<<prevst<<" "<<prevend<<endl;
           }
        
        return remove;
    }
};