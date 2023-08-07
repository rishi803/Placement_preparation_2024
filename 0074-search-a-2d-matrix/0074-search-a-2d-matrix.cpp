class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row= matrix.size(),col= matrix[0].size();
        
        int low=0, high= row*col-1;  // (last index--> treating 2d matrix as 1d matrix);
        
        while(low <= high){
            int mid= low + (high - low)/2; // convert this 1d matrix var as 2d matrix
            
            int x= mid / col;
            int y= mid % col;
            
            if(matrix[x][y] == target) return true;
            
            else if(matrix[x][y] < target) low= mid+1;
            else high= mid-1;
            
        }
        
        return false;
    }
};