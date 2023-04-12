class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b){
        
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int cnt=0;
        sort(intervals.begin(),intervals.end(),cmp);
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