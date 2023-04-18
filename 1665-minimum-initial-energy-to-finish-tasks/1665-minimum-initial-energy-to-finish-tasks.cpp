class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        
        int ans=tasks[0][1];
        int energy=tasks[0][1]-tasks[0][0];
        
        for(int i=1;i<tasks.size();i++){
            
            if(energy<tasks[i][1]){
                 ans+=tasks[i][1]-energy;
                 energy=tasks[i][1]-tasks[i][0];
            }
            else{
                energy=energy-tasks[i][0];
            }
           
        }
        
        return ans;
    }
};