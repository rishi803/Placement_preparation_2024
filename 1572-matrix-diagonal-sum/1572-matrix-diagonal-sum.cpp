class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       
        int sum=0;
        
        for(int i=0;i<mat.size();i++){
            int secy=mat.size()-i-1;
            
            if(secy==i) sum+=mat[i][i];
            else{
                sum+=mat[i][i];
                sum+=mat[i][secy];
            }
        }
        
        return sum;
    }
};