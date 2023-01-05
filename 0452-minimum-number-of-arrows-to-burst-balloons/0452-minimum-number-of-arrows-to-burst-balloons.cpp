class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    
        sort(points.begin(),points.end());
        int fir=INT_MIN,sec=INT_MAX;
        int arrow=1;
        for(auto &interval:points){
            fir=max(fir,interval[0]);
            sec=min(sec,interval[1]);
            
            if(fir>sec){
                arrow++;
                fir=interval[0];
                sec=interval[1];
            }
        }
        return arrow;
    }
};