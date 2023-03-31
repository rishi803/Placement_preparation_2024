class NumMatrix {
public:
    vector<vector<int>> vec;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //Took (m+1, n+1) in order to handle corner cases easily
        vec.resize(m+1, vector<int>(n+1));
        //vec[i][j] = the sum of sub-matrix ending at the cell - (i - 1, j - 1) (starting from the origin (0, 0)).
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                vec[i][j] = vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1] + matrix[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        //remember vec is of size(m+1, n+1)
        //so, if user asks for (r, c), I will consider (r+1, c+1);
        //If that would not have been the case
        //I would simply return
        //return vec[r2][c2] - vec[r1-1][c2] - vec[r2][c1-1] + vec[r1-1][c1-1];
        
        //But, I convert that in (r+1, c+1) format
        
        return vec[r2+1][c2+1] - vec[r1][c2+1] - vec[r2+1][c1] + vec[r1][c1];
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */