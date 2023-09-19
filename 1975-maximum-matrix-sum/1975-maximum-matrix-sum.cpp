class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long ans= 0;
        
        int smallest= INT_MAX;
        int neg_cnt= 0;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                
                ans+= abs(matrix[i][j]);
                
                smallest= min(smallest, abs(matrix[i][j]));
                
                if(matrix[i][j] < 0) neg_cnt++;
                
            }
            
        }
        
        if(neg_cnt % 2 ==0)  return ans;      // even cnt -ve
        
        return ans - (smallest*2);
    }
};