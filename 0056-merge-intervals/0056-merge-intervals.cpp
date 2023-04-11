class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>temp;
        temp.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            
            if(temp.back()[1]>=intervals[i][0]){
                temp.back()[1]=max(temp.back()[1],intervals[i][1]);
            }
            
            else{
                temp.push_back(intervals[i]);
            }
        }
        
        return temp;
    }
};