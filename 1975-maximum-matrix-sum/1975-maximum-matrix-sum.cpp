class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum= 0;
        int neg_cnt=0, smallest= INT_MAX;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                
                sum+= abs(matrix[i][j]);        // man liya sare number +ve ho gaye h
                
                smallest= min(smallest, abs(matrix[i][j])); // agr last me -ve ka cnt odd times raha to sabse choti value ko sum me se hatana hoga jisse max sum mile ab is smallest num ko bhi sum me add kiya tha isliye isko hatane ke liye (2*smallestnumber) krenge
                
                if(matrix[i][j] < 0) neg_cnt++;
                
                
            }
        }
        
        if(neg_cnt % 2 == 0) return sum;
        
        return sum - (2*smallest);
        
        
    }
};