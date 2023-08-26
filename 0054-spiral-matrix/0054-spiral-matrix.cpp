class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int n=matrix.size();
        int m=matrix[0].size();
        int rowup=0, rowb= n-1, colleft=0, colright= m-1;
    int dir= 0;
    vector<int>ans;

    while(rowup <= rowb and colleft <= colright){
         if(dir == 0 ){
               for(int i= colleft; i<= colright; i++){
                   ans.push_back(matrix[rowup][i]);
               }
               rowup++;
               dir= 1;
         }
         else if(dir == 1){
             for(int i= rowup; i<= rowb; i++){
                 ans.push_back(matrix[i][colright]);
             }
             colright--;
             dir= 2;
         }

         else if(dir == 2){
             for(int i= colright; i>= colleft; i--){
                 ans.push_back(matrix[rowb][i]);
             }
             rowb--;
             dir= 3;
         }
         else if(dir == 3){
             for(int i= rowb; i>=rowup; i--){
                 ans.push_back(matrix[i][colleft]);
             }
             colleft++;
             dir= 0;
         }
    }
    return ans;
        
    }
};