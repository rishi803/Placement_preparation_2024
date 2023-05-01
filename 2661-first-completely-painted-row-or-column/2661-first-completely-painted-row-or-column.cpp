class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        
        unordered_map<int,int>mprow,mpcol;
        
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        
        for(int i=0;i<arr.size();i++){
            int rownumber=mp[arr[i]].first;
            int colnumber=mp[arr[i]].second;
            
            mprow[rownumber]++;
            mpcol[colnumber]++;
            
            int maxrow=mprow[rownumber];
            int maxcol=mpcol[colnumber];
            // cout<<maxrow<<" "<<maxcol<<endl;
            
            if(maxrow==mat[0].size() or maxcol==mat.size()) return i;
            
        }
        
        return -1;
        
    }
};