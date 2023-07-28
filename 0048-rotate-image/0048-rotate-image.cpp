class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=0;j<matrix.size();j++){
               
               swap(matrix[j][i],matrix[j][matrix.size()-1-i]);
            }
           
        }
    }
};