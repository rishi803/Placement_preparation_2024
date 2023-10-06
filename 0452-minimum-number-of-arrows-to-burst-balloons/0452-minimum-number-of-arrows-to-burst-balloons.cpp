class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        
        int prevst= points[0][0];
        int prevend= points[0][1];
        int arrow= 1;
        
        for(int i=1; i<points.size(); i++){
            
            if(points[i][0] <= prevend){
                prevend= min(prevend,points[i][1]);  // why min range think ???
            }
            
            else{
                arrow++;
                prevst= points[i][0];
                prevend= points[i][1];
            }
        }
        
        return arrow;
    }
};