class Solution {
public:
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        
        int pref=intervals[0][0];
        int prel=intervals[0][1];
        int ans=0;
        // for(auto i:intervals) cout<<i[0]<< " "<<i[1]<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prel){
                pref=intervals[i][0];
                prel=intervals[i][1];
            }
            else{
                ans++;
            }
        }
        
        return ans;
    }
};