class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        vector<int>ans=points[0];
        
        int cnt=1;
        
        for(int i=1;i<points.size();i++){
            
            vector<int>temp=points[i];
            
            if(ans[1]>=temp[0]){
                ans[0]=max(ans[0],temp[0]);
                ans[1]=min(ans[1],temp[1]);
                // cout<<ans[0]<<" "<<ans[1]<<endl;
            }
            else{
                ans=temp;
                cnt++;
            }
        }
        return cnt;
    }
};