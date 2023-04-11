class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        int prevst=intervals[0][0],prevend=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            
            if(intervals[i][0]<prevend){
                cnt++;
                prevend=min(prevend,intervals[i][1]);
            }
            
            else{
                prevend=intervals[i][1];
            }
        }
        return cnt;
    }
};