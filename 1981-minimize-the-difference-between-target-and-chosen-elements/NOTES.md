return;
}
if(ans<=abs(sum-target)) return;
for(int i=0;i<mat[currow].size();i++){
sum+=mat[currow][i];
help(mat,row,col,currow+1,target,sum);
sum-=mat[currow][i];
// cout<<endl;
}
}
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
int sum=0;
int row_h=mat[0].size(),col_v=mat.size();
help(mat,row_h,col_v,0,target,0);
return ans;
}
};
```
​
SAME BACKTRACKING BUT--> (DESIGN TO IMPLEMENT DP)
​
```
class Solution {
public:
int help(vector<vector<int>>&mat,int row,int col,int currow,int target,int sum){
if(currow>=col) {
return abs(sum-target);
}
int mn=INT_MAX;
for(int i=0;i<mat[currow].size();i++){
mn=min(mn,help(mat,row,col,currow+1,target,sum+mat[currow][i]));
}
return mn;
}
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
int row_h=mat[0].size(),col_v=mat.size();
return help(mat,row_h,col_v,0,target,0);
}
};
```
​
​