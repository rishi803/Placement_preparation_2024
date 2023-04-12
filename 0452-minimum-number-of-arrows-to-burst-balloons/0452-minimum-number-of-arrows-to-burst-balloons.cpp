class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      
        sort(points.begin(),points.end());
        int arrow=1;
        int prevend=points[0][1];
        
        for(int i=1;i<points.size();i++){
            
            if(points[i][0]<=prevend){
                prevend=min(prevend,points[i][1]);
            }
            
            else{
                arrow++;
                prevend=points[i][1];
            }
        }
        
        return arrow;
    }
};